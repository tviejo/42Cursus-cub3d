/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:59:05 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/26 18:17:08 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_map(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] == ' ')
		i++;
	if (line && (line[i] == '1' || line[i] == '0'))
		return (true);
	return (false);
}
int	find_map_size(int fd, t_cub3d *cub3d)
{
	char	*line;
	size_t	i;

	i = 0;
	line = get_next_line(fd);
	while (line && is_map(line) != true)
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line && is_map(line) == true)
	{
		i++;
		if (ft_strlen(line) > cub3d->parsing.map_with)
			cub3d->parsing.map_with = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	cub3d->parsing.map_height = i;
	return (EXIT_SUCCESS);
}

static int	allocate_map(t_cub3d *cub3d)
{
	size_t	i;

	i = 0;
	cub3d->parsing.map = malloc(sizeof(char *) * (cub3d->parsing.map_height + 3));
	if (!cub3d->parsing.map)
		return (EXIT_FAILURE);
	while (i < cub3d->parsing.map_height + 2)
	{
		cub3d->parsing.map[i] = malloc(sizeof(char) * (cub3d->parsing.map_with + 2));
		if (!cub3d->parsing.map[i])
			return (EXIT_FAILURE);
		ft_memset(cub3d->parsing.map[i], '9', cub3d->parsing.map_with + 2);
		cub3d->parsing.map[i][cub3d->parsing.map_with + 1] = '\0';
		i++;
	}
	cub3d->parsing.map[i] = NULL;
	return (EXIT_SUCCESS);
}

static void parse_player(t_cub3d *cub3d, int x, int y, char dir)
{
	if (cub3d->player.x != -1)
		ft_dprintf(2, "error: multiple player\n");
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
static char	*replace_spaces(char *line, t_cub3d *cub3d, int x)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		{
			if (cub3d->player.x != -1)
				return (NULL);
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
	while (i <= cub3d->parsing.map_height && line)
	{
		line = replace_spaces(line, cub3d, i);
		if (line == NULL)
			return (ft_dprintf(2, "error: multiple player\n"), EXIT_FAILURE);
		ft_memcpy(&cub3d->parsing.map[i][1], line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	return (EXIT_SUCCESS);
}
