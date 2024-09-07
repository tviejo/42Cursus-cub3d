/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:08:35 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/07 13:20:46 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_parsing(t_cub3d *cub3d)
{
	cub3d->player.vertical_fov = DEG_VERTICAL_FOV * M_PI / 180.0;
	cub3d->player.pos.x = -1;
	cub3d->player.pos.y = -1;
	cub3d->player.view_height = 0.0;
	cub3d->player.walk_distance = 0.0;
	cub3d->player.walk_height_shift = 0.0;
	cub3d->map.wall_heightscale = 86.3 / DEG_VERTICAL_FOV;
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
	cub3d->map.error = NO_ERROR;
	cub3d->monsters = NULL;
	cub3d->game.last_time = (struct timeval){.tv_sec = 0, .tv_usec = 0};
}
