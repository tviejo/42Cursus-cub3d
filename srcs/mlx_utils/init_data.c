/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:25:40 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/10 13:29:42 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mlx_init_data(t_cub3d *cub3d)
{
	int	i;

	cub3d->mlx.pixel = NULL;
	cub3d->mlx.mlx_img.ptr = NULL;
	cub3d->mlx.wall_tex[North].ptr = NULL;
	cub3d->mlx.wall_tex[South].ptr = NULL;
	cub3d->mlx.wall_tex[West].ptr = NULL;
	cub3d->mlx.wall_tex[East].ptr = NULL;
	cub3d->mlx.open_door_tex.ptr = NULL;
	cub3d->mlx.closed_door_tex.ptr = NULL;
	cub3d->mlx.text[GUN].ptr = NULL;
	i = GUN;
	while (i <= RELOAD)
		cub3d->mlx.text[i++].ptr = NULL;
	return (0);
}
