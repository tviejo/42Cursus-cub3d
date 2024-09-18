/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:22:05 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/18 11:10:25 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_parsing(t_cub3d *c)
{
	int	i;

	i = 0;
	ft_printf("north texture: %s\n", c->map.north_tfname);
	ft_printf("south texture: %s\n", c->map.south_tfname);
	ft_printf("west texture : %s\n", c->map.west_tfname);
	ft_printf("east texture : %s\n", c->map.east_tfname);
	ft_printf("open door texture   : %s\n", c->map.open_door_tfname);
	ft_printf("closed door texture : %s\n", c->map.closed_door_tfname);
	ft_printf("col_floor: %d, %d, %d\n", c->map.col_floor.r,
		c->map.col_floor.g, c->map.col_floor.b);
	ft_printf("col_ceil: %d, %d, %d\n\n\n", c->map.col_ceil.r,
		c->map.col_ceil.g, c->map.col_ceil.b);
	while (i < c->map.height + 2)
	{
		ft_printf("%s\n", c->map.m[i]);
		i++;
	}
	ft_printf("player: %d, %d\n", (int)c->player.pos.x, (int)c->player.pos.y);
}
