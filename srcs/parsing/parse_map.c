/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:59:05 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/28 17:20:25 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	allocate_map(t_cub3d *cub3d)
{
	size_t	i;

	i = 0;
	cub3d->map.m = malloc(sizeof(char *) * (cub3d->map.height + 3));
	if (!cub3d->map.m)
		return (EXIT_FAILURE);
	while (i < cub3d->map.height + 2)
	{
		cub3d->map.m[i] = malloc(sizeof(char) * (cub3d->map.width + 2));
		if (!cub3d->map.m[i])
			return (EXIT_FAILURE);
		ft_memset(cub3d->map.m[i], '9', cub3d->map.width + 2);
		cub3d->map.m[i][cub3d->map.width + 1] = '\0';
		i++;
	}
	cub3d->map.m[i] = NULL;
	return (EXIT_SUCCESS);
}

static void	parse_player(t_cub3d *cub3d, int x, int y, char dir)
{
	cub3d->player.x = x;
	cub3d->player.y = y;
	if (dir == 'N')
		cub3d->player.dir = 0;
	else if (dir == 'E')
		cub3d->player.dir = 90;
	else if (dir == 'S')
		cub3d->player.dir = 180;
	else if (dir == 'W')
		cub3d->player.dir = 270;
}

static bool	is_valid(char c)
{
	if (c == '0' || c == '1' || c == ' ')
		return (true);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	if (c == 'C' || c == 'O')
		return (true);
	return (false);
}

static char	*replace_spaces(char *line, t_cub3d *cub3d, int x)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (is_valid(line[i]) == false)
			cub3d->map.error = INVALID_CHAR;
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
		{
			if (cub3d->player.x != -1)
				cub3d->map.error = MULTIPLE_PLAYER;
			parse_player(cub3d, x, i + 1, line[i]);
			line[i] = '0';
		}
		if (line[i] == ' ')
			line[i] = '9';
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	parse_map(char *line, int fd, t_cub3d *cub3d)
{
	size_t		i;
	static bool	map = false;

	if (map == true)
		return (EXIT_FAILURE);
	map = true;
	if (allocate_map(cub3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	i = 1;
	while (i <= cub3d->map.height && line)
	{
		line = replace_spaces(line, cub3d, i);
		if (cub3d->map.error == MULTIPLE_PLAYER)
			return (ft_dprintf(2, "error: multiple player\n"), EXIT_FAILURE);
		if (cub3d->map.error == INVALID_CHAR)
			return (ft_dprintf(2, "error: invalid char\n"), EXIT_FAILURE);
		ft_memcpy(&cub3d->map.m[i][1], line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	return (EXIT_SUCCESS);
}
