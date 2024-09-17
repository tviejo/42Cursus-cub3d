/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_tex_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 03:47:02 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/17 16:38:25 by ade-sarr         ###   ########.fr       */
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

void	render_tex_ceil_n_floor(t_cub3d *c, t_raycast *rc, t_render_tex *r)
{
	t_rdr_horiz_tex	t;

	t.img_h2 = 0.5 * c->mlx.mlx_img.dim.height;
	t._1_img_h2 = 1.0 / (t.img_h2 * c->map.wall_heightscale);
	t.rel_angle = angles_add(rc->angle, -c->player.dir);
	t.h_diff = c->player.view_height + c->player.walk_height_shift;
	t.h_eye = t.h_diff + t.img_h2 * c->map.wall_heightscale;
	t.pl_tx = 0.5 * c->player.pos.x * TEX_SCALE;
	t.pl_ty = 0.5 * c->player.pos.y * TEX_SCALE;
	t.scale_cos = c->mlx.mlx_img.dim.height * TEX_SCALE / cos(t.rel_angle);
	t.tx_mul = 0.25 * cos(rc->angle) * t._1_img_h2 * t.scale_cos;
	t.ty_mul = 0.25 * sin(rc->angle) * t._1_img_h2 * t.scale_cos;
	t.img_dst = &c->mlx.mlx_img;
	t.texture = r->texFloor;
	t.x = rc->column;
	t.ymax = c->mlx.mlx_img.dim.height;
	t.y = r->y;
	if (r->texFloor->ptr)
		render_floor_column(t);
	t.texture = r->texCeil;
	t.ymax = r->y0;
	t.y = 0;
	t.h_eye = t.img_h2 * c->map.wall_heightscale - t.h_diff;
	if (r->texCeil->ptr)
		render_ceil_column(t);
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
