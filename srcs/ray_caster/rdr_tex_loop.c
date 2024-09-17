/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_tex_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 03:47:02 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/17 10:25:15 by ade-sarr         ###   ########.fr       */
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
	const double	img_h2 = 0.5 * c->mlx.mlx_img.dim.height;
	const double	rel_angle = angles_add(rc->angle, -c->player.dir);
	double			tx;
	double			ty;
	double			tx_mul;
	double			ty_mul;
	double			floor_dist;
	double			real_y;

	tx_mul = 0.25 * cos(rc->angle) * c->mlx.mlx_img.dim.height * TEX_SCALE / cos(rel_angle);
	ty_mul = 0.25 * sin(rc->angle) * c->mlx.mlx_img.dim.height * TEX_SCALE / cos(rel_angle);
	r->ymax = c->mlx.mlx_img.dim.height;
	//r->y = r->y0 + r->height;
	if (r->texFloor->ptr)
		while (r->y < r->ymax)
		{
			floor_dist = (- (c->player.view_height + c->player.walk_height_shift)
			- img_h2 * c->map.wall_heightscale) / (r->y - img_h2);
			real_y = r->y + (c->player.view_height + c->player.walk_height_shift) / floor_dist;
			tx = 0.5 * c->player.pos.x * TEX_SCALE + tx_mul / (real_y - 0.5 * c->mlx.mlx_img.dim.height);
			ty = 0.5 * c->player.pos.y * TEX_SCALE - ty_mul / (real_y - 0.5 * c->mlx.mlx_img.dim.height);
			
			r->shadeCeilFloor = LUM_FADE_DIST / (LUM_FADE_DIST + floor_dist * floor_dist);
			put_pixel(&c->mlx.mlx_img, rc->column, r->y, get_shaded_ceilfloor(
					get_pixel(r->texFloor, (int)tx & (TEX_SIZE - 1), (int)ty & (TEX_SIZE - 1)), r->shadeCeilFloor));
			r->y++;
		}
	r->ymax = r->y0;
	r->y = 0;
	if (r->texCeil->ptr)
		while (r->y < r->ymax)
		{
			floor_dist = ((c->player.view_height + c->player.walk_height_shift)
			- img_h2 * c->map.wall_heightscale) / (r->y - img_h2);
			real_y = r->y - (c->player.view_height + c->player.walk_height_shift) / floor_dist;
			tx = - 0.5 * c->player.pos.x * TEX_SCALE + tx_mul / (real_y - 0.5 * c->mlx.mlx_img.dim.height);
			ty = + 0.5 * c->player.pos.y * TEX_SCALE + ty_mul / (real_y - 0.5 * c->mlx.mlx_img.dim.height);
					
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
