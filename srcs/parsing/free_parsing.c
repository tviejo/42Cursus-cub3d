/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:22:50 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/09 11:07:25 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_parsing(t_map *map)
{
	int	i;

	i = 0;
	if (map->north_tfname)
		free(map->north_tfname);
	if (map->south_tfname)
		free(map->south_tfname);
	if (map->west_tfname)
		free(map->west_tfname);
	if (map->east_tfname)
		free(map->east_tfname);
	if (map->open_door_tfname)
		free(map->open_door_tfname);
	if (map->closed_door_tfname)
		free(map->closed_door_tfname);
	if (map->m)
	{
		while (i < map->height + 2 && map->m[i])
		{
			free(map->m[i]);
			i++;
		}
		free(map->m);
	}
}
