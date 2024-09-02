/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:08:35 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/03 01:33:39 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_parsing(t_cub3d *cub3d)
{
	cub3d->map.m = NULL;
	cub3d->map.height = 0;
	cub3d->map.width = 0;
	cub3d->map.north_tfname = NULL;
	cub3d->map.south_tfname = NULL;
	cub3d->map.west_tfname = NULL;
	cub3d->map.east_tfname = NULL;
	cub3d->map.col_floor.r = -1;
	cub3d->map.col_floor.g = -1;
	cub3d->map.col_floor.b = -1;
	cub3d->map.col_ceil.r = -1;
	cub3d->map.col_ceil.g = -1;
	cub3d->map.col_ceil.b = -1;
	cub3d->map.wall_heightscale = 0.8 * WINDOW_WIDTH / WINDOW_HEIGHT;
	cub3d->map.error = NO_ERROR;
	cub3d->player.pos.x = -1;
	cub3d->player.pos.y = -1;
	cub3d->player.fov = 60.0 * M_PI / 180.0;
}
