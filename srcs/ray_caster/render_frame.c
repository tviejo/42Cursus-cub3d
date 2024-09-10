/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:55:40 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/10 04:08:49 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_ray(t_cub3d *c, t_raycast *r, int item)
{
	if (c->game.rendering_mode == RENDER_COLOR)
		render_ray_colored(c, r, item);
	if (c->game.rendering_mode == RENDER_TEXTURE)
		render_ray_textured(c, r, item);
}

void	cast_ray(t_cub3d *c, t_raycast *r)
{
	t_point			mapc;
	const t_size2i	step = {.x = r->v_inc.x, .y = r->h_inc.y};
	int				mapitem;

	mapc = (t_point){.x = c->player.pos.x, .y = c->player.pos.y};
	while (true)
	{
		if (r->v_dist < r->h_dist)
		{
			r->v_dist += r->v_dist_inc;
			mapc.x += step.x;
			r->vertical_wall = true;
		}
		else
		{
			r->h_dist += r->h_dist_inc;
			mapc.y += step.y;
			r->vertical_wall = false;
		}
		mapitem = c->map.m[mapc.y][mapc.x];
		if (mapitem != '0' && mapitem != 'O' && mapitem != '9')
			break ;
	}
	r->mapc = mapc;
	render_ray(c, r, mapitem);
}

void	init_ray_v_inter(t_raycast *r, double angle, t_pointd pl_pos)
{
	t_pointd	delta;

	if (angle > NORTH_ANGLE && angle < SOUTH_ANGLE)
	{
		r->v_inc.x = -1.0;
		r->v_inter.x = (int)pl_pos.x;
	}
	else
	{
		r->v_inc.x = 1.0;
		r->v_inter.x = (int)pl_pos.x + 1.0;
	}
	r->v_inc.y = -r->v_inc.x * tan(angle);
	delta.x = r->v_inter.x - pl_pos.x;
	r->v_inter.y = -delta.x * tan(angle) + pl_pos.y;
	delta.y = r->v_inter.y - pl_pos.y;
	r->v_dist = sqrt(delta.x * delta.x + delta.y * delta.y);
	r->v_dist_inc = sqrt(r->v_inc.x * r->v_inc.x + r->v_inc.y * r->v_inc.y);
}
/*if (angle == NORTH_ANGLE || angle == SOUTH_ANGLE)
		r->v_inc.x = 0.0;*/

void	init_ray_h_inter(t_raycast *r, double angle, t_pointd pl_pos)
{
	t_pointd	delta;

	if (angle < WEST_ANGLE)
	{
		r->h_inc.y = -1.0;
		r->h_inter.y = (int)pl_pos.y;
	}
	else
	{
		r->h_inc.y = 1.0;
		r->h_inter.y = (int)pl_pos.y + 1.0;
	}
	r->h_inc.x = -r->h_inc.y / tan(angle);
	delta.y = r->h_inter.y - pl_pos.y;
	r->h_inter.x = -delta.y / tan(angle) + pl_pos.x;
	delta.x = r->h_inter.x - pl_pos.x;
	r->h_dist = sqrt(delta.x * delta.x + delta.y * delta.y);
	r->h_dist_inc = sqrt(r->h_inc.x * r->h_inc.x + r->h_inc.y * r->h_inc.y);
}

/*if (angle == EAST_ANGLE || angle == WEST_ANGLE)
		r->h_inc.y = 0.0;*/

/*
void	render_frame(t_cub3d *c)
{
	t_raycast	ray;
	double		angle_inc;

	//img_clear128(&c->mlx.mlx_img);
	ray.angle = angles_add(c->player.dir, 0.5 * c->player.fov);
	angle_inc = -c->player.fov / c->mlx.mlx_img.dim.width;
	ray.column = 0;
	while (ray.column < c->mlx.mlx_img.dim.width)
	{
		init_ray_h_inter(&ray, ray.angle, c->player.pos);
		init_ray_v_inter(&ray, ray.angle, c->player.pos);
		cast_ray(c, &ray,
			(t_point){.x = c->player.pos.x, .y = c->player.pos.y});
		ray.column++;
		ray.angle = angles_add(ray.angle, angle_inc);
	}
}*/

void	render_frame(t_cub3d *c)
{
	t_raycast	ray;
	double		dist_to_plane;

	draw_floor_n_ceil(c);
	dist_to_plane = c->mlx.mlx_img.dim.height
		/ tan(0.5 * c->player.vertical_fov);
	ray.column = 0;
	ray.angle = angles_add(atan2(0.5 * c->mlx.mlx_img.dim.width
				- (ray.column - 0.5), dist_to_plane), c->player.dir);
	while (ray.column < c->mlx.mlx_img.dim.width)
	{
		init_ray_h_inter(&ray, ray.angle, c->player.pos);
		init_ray_v_inter(&ray, ray.angle, c->player.pos);
		cast_ray(c, &ray);
		ray.column++;
		ray.angle = angles_add(atan2(0.5 * c->mlx.mlx_img.dim.width
					- (ray.column - 0.5), dist_to_plane), c->player.dir);
	}
}
