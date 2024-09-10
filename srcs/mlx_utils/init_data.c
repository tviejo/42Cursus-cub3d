/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:25:40 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/10 04:41:14 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mlx_init_data(t_cub3d *cub3d)
{
	cub3d->mlx.pixel = NULL;
	cub3d->mlx.mlx_img.ptr = NULL;
	cub3d->mlx.wall_tex[North].ptr = NULL;
	cub3d->mlx.wall_tex[South].ptr = NULL;
	cub3d->mlx.wall_tex[West].ptr = NULL;
	cub3d->mlx.wall_tex[East].ptr = NULL;
	cub3d->mlx.open_door_tex.ptr = NULL;
	cub3d->mlx.closed_door_tex.ptr = NULL;
	cub3d->mlx.text[GUN].ptr = NULL;
	return (0);
}
