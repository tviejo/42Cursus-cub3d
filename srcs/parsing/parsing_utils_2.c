/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:25:39 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/14 19:28:05 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
				return (free(line), EXIT_FAILURE);
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
}
