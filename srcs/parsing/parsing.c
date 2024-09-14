/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:57:43 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/14 19:27:46 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	error_open_map_file(char *filename)
{
	ft_dprintf(2, "Echec sur ouverture du fichier de map [%s]: ", filename);
	perror(NULL);
	return (EXIT_FAILURE);
}

static int	open_and_size(char *filename, t_cub3d *cub3d)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	find_map_size(fd, cub3d);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

static int	parse_file_core(int fd, char *line, t_cub3d *cub3d)
{
	while (line && ready_to_parse_map(cub3d) == false)
	{
		if (is_texture(line))
		{
			if (parse_texture(line, cub3d) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (is_color(line))
		{
			if (parse_color(line, cub3d) == false)
				return (free(line), EXIT_FAILURE);
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	find_map(cub3d, fd, line);
	return (EXIT_SUCCESS);
}

static int	parse_file(char *filename, t_cub3d *cub3d)
{
	char	*line;
	int		fd;

	if (open_and_size(filename, cub3d) == EXIT_FAILURE)
		return (error_open_map_file(filename));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (error_open_map_file(filename));
	line = get_next_line(fd);
	if (parse_file_core(fd, line, cub3d) == EXIT_FAILURE)
		return (close(fd), EXIT_FAILURE);
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
