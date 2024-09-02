/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:22:05 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/01 20:44:32 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_parsing(t_cub3d *c)
{
	int	i;

	i = 0;
	printf("north texture: %s\n", c->map.north_tfname);
	printf("south texture: %s\n", c->map.south_tfname);
	printf("west texture : %s\n", c->map.west_tfname);
	printf("east texture : %s\n", c->map.east_tfname);
	printf("col_floor: %d, %d, %d\n", c->map.col_floor.r,
		c->map.col_floor.g, c->map.col_floor.b);
	printf("col_ceil: %d, %d, %d\n\n\n", c->map.col_ceil.r,
		c->map.col_ceil.g, c->map.col_ceil.b);
	while (i < c->map.height + 2)
	{
		printf("%s\n", c->map.m[i]);
		i++;
	}
	printf("player: %f, %f\n", c->player.pos.x, c->player.pos.y);
}
