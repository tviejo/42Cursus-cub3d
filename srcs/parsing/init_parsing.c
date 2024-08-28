/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:08:35 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/28 15:02:43 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_parsing(t_cub3d *cub3d)
{
	cub3d->map.height = 0;
	cub3d->map.width = 0;
	cub3d->map.no = NULL;
	cub3d->map.so = NULL;
	cub3d->map.we = NULL;
	cub3d->map.ea = NULL;
	cub3d->map.col_floor.r = -1;
	cub3d->map.col_floor.g = -1;
	cub3d->map.col_floor.b = -1;
	cub3d->map.col_ceil.r = -1;
	cub3d->map.col_ceil.g = -1;
	cub3d->map.col_ceil.b = -1;
	cub3d->map.m = NULL;
	cub3d->player.x = -1;
	cub3d->player.y = -1;
	cub3d->map.error = NO_ERROR;
}
