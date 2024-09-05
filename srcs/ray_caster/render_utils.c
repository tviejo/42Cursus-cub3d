/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:57:27 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/05 14:06:15 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_directions	get_wall_orientation(double ray_angle, bool vertical_wall)
{
	if (vertical_wall)
	{
		if (ray_angle > NORTH_ANGLE && ray_angle < SOUTH_ANGLE)
			return (West);
		else
			return (East);
	}
	else
	{
		if (ray_angle < WEST_ANGLE)
			return (North);
		else
			return (South);
	}
}

int	get_wall_color(t_directions orientation, double distance, int wallitem)
{
	static const int	colors[] = {0xf70020, 0x7f3000, 0x0050ff, 0x000070};
	int					c;
	double				fade;

	c = colors[orientation];
	if (wallitem == 'C')
		c = COL_MAGENTA;
	fade = 40.0 / (40.0 + distance * distance);
	c = ((int)(((c >> 16) & 255) * fade) << 16)
		+ ((int)(((c >> 8) & 255) * fade) << 8)
		+ (int)((c & 255) * fade);
	return (c);
}

//m = x - (float)(int)x;
//m += (float)(m<0.f);
// branchless form to add one if m is negative but not zero

void	draw_floor_n_ceil(t_cub3d *c)
{
	t_pt2d	p0;
	t_pt2d	p1;
	int		ymax;

	p0 = (t_pt2d){.x = 0, .y = 0, .color = c->mlx.color_ceil};
	p1 = (t_pt2d){.x = c->mlx.mlx_img.dim.width - 1, .y = 0};
	ymax = (c->mlx.mlx_img.dim.height >> 1) - 1;
	while (p0.y < ymax)
	{
		//p0.color = ;
		draw_line(&c->mlx.mlx_img, p0, p1);
		p0.y++;
		p1.y++;
	}
	p0 = (t_pt2d){.x = 0, .y = ymax + 1, .color = c->mlx.color_floor};
	p1.y = ymax + 1;
	ymax = c->mlx.mlx_img.dim.height - 1;
	while (p0.y < ymax)
	{
		//p0.color = ;
		draw_line(&c->mlx.mlx_img, p0, p1);
		p0.y++;
		p1.y++;
	}
}
