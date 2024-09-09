/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:25:40 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/09 21:04:48 by tviejo           ###   ########.fr       */
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
	cub3d->mlx.text[GUN].ptr = NULL;
	return (0);
}
