/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:59:05 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/07 11:18:56 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	allocate_map(t_cub3d *cub3d)
{
	int	i;

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

static void	parse_player(t_player *pl, int x, int y, int cdir)
{
	pl->pos.x = x + 0.5;
	pl->pos.y = y + 0.5;
	pl->dir = 0.0;
	if (cdir == 'N')
		rotate_player(pl, NORTH_ANGLE);
	else if (cdir == 'E')
		rotate_player(pl, EAST_ANGLE);
	else if (cdir == 'S')
		rotate_player(pl, SOUTH_ANGLE);
	else if (cdir == 'W')
		rotate_player(pl, WEST_ANGLE);
}

static bool	is_valid(int c)
{
	if (c == '0' || c == '1' || c == ' ')
		return (true);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	if (c == 'C' || c == 'O')
		return (true);
	if (c == 'A')
		return (true);
	return (false);
}

static char	*replace_spaces(t_cub3d *cub3d, char *line, int i_line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (!is_valid(line[i]))
			cub3d->map.error = INVALID_CHAR;
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
		{
			if (cub3d->player.pos.x != -1)
				cub3d->map.error = MULTIPLE_PLAYER;
			parse_player(&cub3d->player, i + 1, i_line, line[i]);
			line[i] = '0';
		}
		if (line[i] == ' ')
			line[i] = '9';
		if (line[i] == 'A')
		{
			add_back_monster(cub3d, new_monster((t_pointd){ .x = i + 1 + 0.5, .y = i_line + 0.5}, 10));
			line[i] = '0';
		}
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	parse_map(t_cub3d *cub3d, int fd, char *line)
{
	int	i_line;

	if (cub3d->map.m)
		return (ft_dprintf(2, "Error: map already loaded !\n"), EXIT_FAILURE);
	if (allocate_map(cub3d) == EXIT_FAILURE)
		return (ft_dprintf(2, "Error: allocate_map(): malloc fails !\n"),
			EXIT_FAILURE);
	i_line = 1;
	while (i_line <= cub3d->map.height && line)
	{
		line = replace_spaces(cub3d, line, i_line);
		if (cub3d->map.error == MULTIPLE_PLAYER)
			return (ft_dprintf(2, "Error: multiple player\n"),
				free(line), EXIT_FAILURE);
		if (cub3d->map.error == INVALID_CHAR)
			return (ft_dprintf(2, "Error: invalid char\n"),
				free(line), EXIT_FAILURE);
		ft_memcpy(&cub3d->map.m[i_line][1], line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
		i_line++;
	}
	free(line);
	return (EXIT_SUCCESS);
}
