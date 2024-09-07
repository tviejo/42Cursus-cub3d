/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:22:50 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/07 11:04:37 by tviejo           ###   ########.fr       */
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
