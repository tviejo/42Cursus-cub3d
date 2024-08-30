/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:25:40 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/30 14:03:17 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mlx_init_data(t_cub3d *cub3d)
{
	cub3d->mlx.pixel = NULL;
	cub3d->mlx.mlx_img.ptr = NULL;
	cub3d->mlx.text_north.ptr = NULL;
	cub3d->mlx.text_south.ptr = NULL;
	cub3d->mlx.text_west.ptr = NULL;
	cub3d->mlx.text_east.ptr = NULL;
	return (0);
}
