/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:55:40 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/08/31 11:52:34 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//m = x - (float)(int)x;
//m += (float)(m<0.f);
// branchless form to add one if m is negative but not zero

/*void	render_column(t_cub3d *c, int x, double angle)
{
	t_pointd	target;

	if (angle <)
	target.x = (int)(c->player.x);
}*/

void	render_frame(t_cub3d *c)
{
	int		x;
	double	angle;
	double	angle_inc;

	angle = c->player.dir - 0.5 * c->player.fov;
	angle_inc = c->player.fov / c->mlx.mlx_img.dim.width;
	x = 0;
	while (x < c->mlx.mlx_img.dim.width)
	{
		//render_column(c, x, angle);
		x++;
		angle += angle_inc;
	}
}
