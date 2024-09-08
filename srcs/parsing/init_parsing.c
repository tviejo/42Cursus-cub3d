/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:08:35 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/08 01:13:38 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_parsing(t_cub3d *cub)
{
	cub->game.minimap_size = 20;
	cub->game.minimap_center = (t_point){{130}, {130}};
	cub->player.vertical_fov = DEG_VERTICAL_FOV * M_PI / 180.0;
	cub->player.pos.x = -1;
	cub->player.pos.y = -1;
	cub->player.view_height = 0.08 * cub->mlx.mlx_img.dim.height;
	cub->player.walk_distance = 0.0;
	cub->player.walk_height_shift = 0.0;
	cub->map.wall_heightscale = 86.3 / DEG_VERTICAL_FOV;
	cub->map.m = NULL;
	cub->map.height = 0;
	cub->map.width = 0;
	cub->map.north_tfname = NULL;
	cub->map.south_tfname = NULL;
	cub->map.west_tfname = NULL;
	cub->map.east_tfname = NULL;
	cub->map.col_floor.r = -1;
	cub->map.col_floor.g = -1;
	cub->map.col_floor.b = -1;
	cub->map.col_ceil.r = -1;
	cub->map.col_ceil.g = -1;
	cub->map.col_ceil.b = -1;
	cub->map.error = NO_ERROR;
}
