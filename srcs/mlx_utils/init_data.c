/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:25:40 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/17 14:09:32 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mlx_init_data(t_cub3d *cub)
{
	int		i;
	float	dist;

	cub->mlx.slices_zbuffer = NULL;
	cub->mlx.mlx_img.ptr = NULL;
	cub->mlx.wall_tex[North].ptr = NULL;
	cub->mlx.wall_tex[South].ptr = NULL;
	cub->mlx.wall_tex[West].ptr = NULL;
	cub->mlx.wall_tex[East].ptr = NULL;
	cub->mlx.open_door_tex.ptr = NULL;
	cub->mlx.closed_door_tex.ptr = NULL;
	i = 0;
	while (i < TXID_MAXIMUM)
		cub->mlx.text[i++].ptr = NULL;
	i = 0;
	while (i < SHADE_TABLE_SIZE)
	{
		dist = i / (float)SHADE_PER_DIST;
		cub->mlx.shade_table[i] = LUM_FADE_DIST / (LUM_FADE_DIST + dist * dist);
		i++;
	}
	return (0);
}
