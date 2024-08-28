/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:57:43 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/28 15:15:05 by ade-sarr         ###   ########.fr       */
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
		if (ft_strlen(line) > cub3d->map.width)
			cub3d->map.width = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	cub3d->map.height = i;
	return (EXIT_SUCCESS);
}

static int	open_and_size(char *file, t_cub3d *cub3d)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	find_map_size(fd, cub3d);
	close(fd);
	return (EXIT_SUCCESS);
}

static int	parse_file(char *file, t_cub3d *cub3d)
{
	char	*line;
	int		fd;

	if (open_and_size(file, cub3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (is_map(line) == true)
		{
			if (parse_map(line, fd, cub3d) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (is_texture(line) == true)
			parse_texture(line, cub3d);
		else if (is_color(line) == true)
			parse_color(line, cub3d);
		else
			free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (EXIT_SUCCESS);
}

int	parse_cub(char *file, t_cub3d *cub3d)
{
	init_parsing(cub3d);
	if (parse_file(file, cub3d) == EXIT_FAILURE)
	{
		free_parsing(cub3d);
		return (EXIT_FAILURE);
	}
	if (check_parsing(cub3d) == EXIT_FAILURE)
	{
		free_parsing(cub3d);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
