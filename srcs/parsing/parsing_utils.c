/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:57:43 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/30 14:06:39 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line && !is_map(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line && is_map(line))
	{
		i++;
		if ((int)ft_strlen(line) > cub3d->map.width)
			cub3d->map.width = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	cub3d->map.height = i;
	return (EXIT_SUCCESS);
}
