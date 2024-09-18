/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:25:39 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/18 13:41:03 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_invalid_line(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '#')
		return (false);
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] != '\n')
	{
		ft_dprintf(2, "Error: Invalid line\n");
		return (true);
	}
	return (false);
}

bool	is_map(char *line)
{
	while (line && *line == ' ')
		line++;
	return (line && (*line == '1' || *line == '0'));
}

int	find_map(t_cub3d *cub3d, int fd, char *line)
{
	while (line)
	{
		if (is_map(line))
		{
			if (parse_map(cub3d, fd, line) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (cub3d->map.m && is_invalid_line(line))
		{
			ft_dprintf(2, "Error\nInvalid line after map\n");
			free(line);
			ft_close(cub3d, NULL);
			return (EXIT_FAILURE);
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
}
