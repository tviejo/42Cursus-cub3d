/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:22:05 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/28 21:44:42 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_parsing(t_cub3d *cub3d)
{
	size_t	i;

	i = 0;
	printf("north texture: %s\n", cub3d->map.no);
	printf("south texture: %s\n", cub3d->map.so);
	printf("west texture : %s\n", cub3d->map.we);
	printf("east texture : %s\n", cub3d->map.ea);
	printf("col_floor: %d, %d, %d\n", cub3d->map.col_floor.r,
		cub3d->map.col_floor.g, cub3d->map.col_floor.b);
	printf("col_ceil: %d, %d, %d\n\n\n", cub3d->map.col_ceil.r,
		cub3d->map.col_ceil.g, cub3d->map.col_ceil.b);
	while (i < cub3d->map.height + 2)
	{
		printf("%s\n", cub3d->map.m[i]);
		i++;
	}
	printf("player: %f, %f\n", cub3d->player.x, cub3d->player.y);
}
