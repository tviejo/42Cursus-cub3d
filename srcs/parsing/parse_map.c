/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:59:05 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/25 14:44:00 by tviejo           ###   ########.fr       */
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
	cub3d->parsing.map = malloc(sizeof(char *) * (cub3d->parsing.map_height + 1));
	if (!cub3d->parsing.map)
		return (EXIT_FAILURE);
	while (i < cub3d->parsing.map_height)
	{
		cub3d->parsing.map[i] = malloc(sizeof(char) * (cub3d->parsing.map_with + 1));
		if (!cub3d->parsing.map[i])
			return (EXIT_FAILURE);
		ft_memset(cub3d->parsing.map[i], '0', cub3d->parsing.map_with);
		cub3d->parsing.map[i][cub3d->parsing.map_with] = '\0';
		i++;
	}
	cub3d->parsing.map[i] = NULL;
	return (EXIT_SUCCESS);
}

static char	*replace_spaces(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == ' ')
			line[i] = '0';
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
	ft_dprintf(1, "Parsing map\n");
	if (allocate_map(cub3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	i = 0;
	while (i < cub3d->parsing.map_height && line)
	{
		line = replace_spaces(line);
		cub3d->parsing.map[i] = ft_memcpy(cub3d->parsing.map[i], line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	return (EXIT_SUCCESS);
}
