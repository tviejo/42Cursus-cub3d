/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:55:40 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/08/31 18:02:18 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//m = x - (float)(int)x;
//m += (float)(m<0.f);
// branchless form to add one if m is negative but not zero
/*
void	render_column(t_cub3d *c, t_raycast *r)
{
	if (angle <)
	target.x = (int)(c->player.x);
}

void	render_frame(t_cub3d *cub)
{
	t_raycast	ray;
	double		angle_inc;

	ray.angle = cub->player.dir - 0.5 * cub->player.fov;
	angle_inc = cub->player.fov / cub->mlx.mlx_img.dim.width;
	ray.column = 0;
	while (ray.column < cub->mlx.mlx_img.dim.width)
	{
		if (angle )
		render_column(cub, &ray);
		ray.column++;
		ray.angle += angle_inc;
	}
}
*/