/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_colored.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:54:49 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/18 11:11:36 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_ray_colored(t_cub3d *c, t_raycast *r, int wallitem)
{
	double	p_wall_dist;
	int		height;
	int		y0;
	t_pt2d	p0;
	t_pt2d	p1;

	if (r->vertical_wall)
		p_wall_dist = r->v_dist - r->v_dist_inc;
	else
		p_wall_dist = r->h_dist - r->h_dist_inc;
	p_wall_dist *= cos(c->player.dir - r->angle);
	c->mlx.slices_zbuffer[r->column] = p_wall_dist;
	height = c->map.wall_heightscale * c->mlx.mlx_img.dim.height / p_wall_dist;
	y0 = ((c->mlx.mlx_img.dim.height - height) >> 1)
		+ (c->player.view_height + c->player.walk_height_shift) / p_wall_dist;
	p0 = (t_pt2d){.x = r->column, .y = y0, .color
		= get_wall_color(get_wall_orientation(r->angle, r->vertical_wall),
			p_wall_dist, wallitem)};
	p1 = (t_pt2d){.x = p0.x, .y = y0 + height};
	draw_line(&c->mlx.mlx_img, p0, p1);
}

/*
void	render_ray_colored_v1(t_cub3d *c, t_raycast *r, bool vertical_wall,
							int wallitem)
{
	double	p_wall_dist;
	int		height;
	int		y0;
	t_pt2d	p0;
	t_pt2d	p1;

	if (vertical_wall)
		p_wall_dist = r->v_dist - r->v_dist_inc;
	else
		p_wall_dist = r->h_dist - r->h_dist_inc;
	p_wall_dist *= cos(c->player.dir - r->angle);
	height = c->map.wall_heightscale * c->mlx.mlx_img.dim.height / p_wall_dist;
	y0 = (c->mlx.mlx_img.dim.height - height) >> 1;
	p0 = (t_pt2d){.x = r->column, .y = y0,
		.color = get_wall_color(get_wall_orientation(r->angle, vertical_wall),
			p_wall_dist, wallitem)};
	p1 = (t_pt2d){.x = p0.x, .y = y0 + height, .color = c->mlx.color_floor};
	draw_line(&c->mlx.mlx_img, p0, p1);
	if (y0 > 0)
		draw_line(&c->mlx.mlx_img,
			(t_pt2d){.x = p0.x, .y = 0, .color = c->mlx.color_ceil}, p0);
	if (y0 + height < c->mlx.mlx_img.dim.height - 1)
		draw_line(&c->mlx.mlx_img, p1,
			(t_pt2d){.x = p0.x, .y = c->mlx.mlx_img.dim.height - 1});
}
*/
