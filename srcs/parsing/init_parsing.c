/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:08:35 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/10 04:43:04 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_parsing(t_cub3d *cub)
{
	cub->player.pos = (t_pointd){{-1}, {-1}};
	cub->map.m = NULL;
	cub->map.height = 0;
	cub->map.width = 0;
	cub->map.north_tfname = NULL;
	cub->map.south_tfname = NULL;
	cub->map.west_tfname = NULL;
	cub->map.east_tfname = NULL;
	cub->map.open_door_tfname = NULL;
	cub->map.closed_door_tfname = NULL;
	cub->map.col_floor = (t_color){-1, -1, -1};
	cub->map.col_ceil = (t_color){-1, -1, -1};
	cub->map.error = NO_ERROR;
}
