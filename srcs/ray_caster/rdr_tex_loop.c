/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_tex_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 03:47:02 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/16 18:41:26 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	put_pixel(t_image *img, int x, int y, int color)
{
	*(t_uint *)(img->pixels + y * img->line_size + 4 * x) = color;
}

static inline int	get_pixel(t_image *img, int x, int y)
{
	return (*(t_uint *)(img->pixels + y * img->line_size + 4 * x));
}

static inline int	get_shaded_color(int color, double shade, int item)
{
	if (item == 'C')
		return (color);
	return (
		((int)(((color >> 16) & 255) * shade) << 16)
		+ ((int)(((color >> 8) & 255) * shade) << 8)
		+ (int)((color & 255) * shade));
}

static inline int	get_shaded_ceilfloor(int color, double shade)
{
	return (
		((int)(((color >> 16) & 255) * shade) << 16)
		+ ((int)(((color >> 8) & 255) * shade) << 8)
		+ (int)((color & 255) * shade));
}

void	render_tex_ceil_n_floor(t_cub3d *c, t_raycast *rc, t_render_tex *r)
{
	const double	rel_angle = angles_add(rc->angle, -c->player.dir);
	double			tx;
	double			ty;
	double			tx_mul;
	double			ty_mul;
	double			floor_dist;
	//double			delta_y;

	tx_mul = 0.33 * cos(rc->angle) * c->mlx.mlx_img.dim.height * TEX_SCALE / cos(rel_angle);
	ty_mul = 0.33 * sin(rc->angle) * c->mlx.mlx_img.dim.height * TEX_SCALE / cos(rel_angle);
	r->ymax = c->mlx.mlx_img.dim.height;
	//r->y = r->y0 + r->height;
	while (r->y < r->ymax)
	{
		floor_dist = c->map.wall_heightscale * c->mlx.mlx_img.dim.height / (2.0 * r->y - c->mlx.mlx_img.dim.height);
		//delta_y = (c->player.view_height + c->player.walk_height_shift) / floor_dist;
		tx = 0.5 * c->player.pos.x * TEX_SCALE + tx_mul / (r->y - 0.5 * c->mlx.mlx_img.dim.height);
		ty = 0.5 * c->player.pos.y * TEX_SCALE - ty_mul / (r->y - 0.5 * c->mlx.mlx_img.dim.height);
		
		r->shadeCeilFloor = LUM_FADE_DIST / (LUM_FADE_DIST + floor_dist * floor_dist);
		put_pixel(&c->mlx.mlx_img, rc->column, r->y /*+ delta_y*/, get_shaded_ceilfloor(
				get_pixel(r->texFloor, (int)tx & (TEX_SIZE - 1), (int)ty & (TEX_SIZE - 1)), r->shadeCeilFloor));
		r->y++;
	}
	r->ymax = r->y0;
	r->y = 0;
	while (r->y < r->ymax)
	{
		floor_dist = c->map.wall_heightscale * c->mlx.mlx_img.dim.height / (2.0 * r->y - c->mlx.mlx_img.dim.height);
		//delta_y = (c->player.view_height + c->player.walk_height_shift) / floor_dist;
		tx = - 0.5 * c->player.pos.x * TEX_SCALE + tx_mul / (r->y - 0.5 * c->mlx.mlx_img.dim.height);
		ty = - 0.5 * c->player.pos.y * TEX_SCALE - ty_mul / (r->y - 0.5 * c->mlx.mlx_img.dim.height);
				
		r->shadeCeilFloor = LUM_FADE_DIST / (LUM_FADE_DIST + floor_dist * floor_dist);
		put_pixel(&c->mlx.mlx_img, rc->column, r->y /*+ delta_y*/, get_shaded_ceilfloor(
				get_pixel(r->texCeil, (int)tx & (TEX_SIZE - 1), (int)ty & (TEX_SIZE - 1)), r->shadeCeilFloor));
		r->y++;
	}
}

void	render_ray_textured(t_cub3d *c, t_raycast *rc, int item)
{
	t_render_tex	r;

	if (render_ray_tex_init(c, rc, &r, item) == EXIT_FAILURE)
		return ;
	r.ymax = r.y0 + r.height;
	r.ftex_yinc = 1.0 * TEX_SCALE / (double)r.height;
	r.ftex_y = 0.0;
	if (r.y0 < 0)
	{
		r.ftex_y = -r.y0 * r.ftex_yinc;
		r.y0 = 0;
	}
	if (r.ymax > c->mlx.mlx_img.dim.height)
		r.ymax = c->mlx.mlx_img.dim.height;
	r.y = r.y0;
	while (r.y < r.ymax)
	{
		r.tex_y = (int)r.ftex_y & r.tex_modulo_m1;
		put_pixel(&c->mlx.mlx_img, rc->column, r.y, get_shaded_color(
				get_pixel(r.tex, r.tex_x, r.tex_y), r.shade, item));
		r.ftex_y += r.ftex_yinc;
		r.y++;
	}
	if (c->game.rendering_mode == RENDER_TEXTURE)
		render_tex_ceil_n_floor(c, rc, &r);
}
