/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:57:43 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/30 14:11:15 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	open_and_size(char *filename, t_cub3d *cub3d)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	find_map_size(fd, cub3d);
	close(fd);
	return (EXIT_SUCCESS);
}

static int	parse_file_core(int fd, char *line, t_cub3d *cub3d)
{
	while (line)
	{
		if (is_map(line))
		{
			if (parse_map(cub3d, fd, line) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (is_texture(line))
		{
			if (parse_texture(line, cub3d) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (is_color(line))
			parse_color(line, cub3d);
		else
			free(line);
		line = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
}

static int	parse_file(char *filename, t_cub3d *cub3d)
{
	char	*line;
	int		fd;

	if (open_and_size(filename, cub3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (parse_file_core(fd, line, cub3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}

int	parse_cub3d(char *filename, t_cub3d *cub)
{
	init_parsing(cub);
	if (parse_file(filename, cub) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_parsing(cub) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
