/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:28:37 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/15 17:50:05 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline static void	put_pixel(t_image *img, int x, int y, int color)
{
	*(t_uint *)(img->pixels + y * img->line_size + 4 * x) = color;
}

inline static int	get_pixel(t_image *img, int x, int y)
{
	return (*(t_uint *)(img->pixels + y * img->line_size + 4 * x));
}

inline static int	get_shaded_color(int color, double shade)
{
	return (
		((int)(((color >> 16) & 255) * shade) << 16)
		+ ((int)(((color >> 8) & 255) * shade) << 8)
		+ (int)((color & 255) * shade));
}

static int	draw_slice_init(t_cub3d *c, t_sprite *spr, t_render_tex *r,
							int img_num)
{
	r->w_dist = spr->dist;
	r->tex = &spr->images[img_num].img;
	if (r->tex->ptr == NULL)
		return (EXIT_FAILURE);
	if (c->mlx.slices_zbuffer[spr->column] < r->w_dist)
		return (EXIT_FAILURE);
	r->shade = TEX_FADE_DIST / (TEX_FADE_DIST + r->w_dist * r->w_dist);
	r->tex_modulo_m1 = TEX_SIZE - 1;
	r->tex_x = (int)(0.79 * spr->x_spot * TEX_SCALE * spr->ratio_w_h)
		& r->tex_modulo_m1;
	r->height = spr->height;
	r->y0 = (140 + c->player.view_height + c->player.walk_height_shift)
		/ r->w_dist + ((c->mlx.mlx_img.dim.height - r->height) >> 1);
	return (EXIT_SUCCESS);
}

void	draw_slice(t_cub3d *c, t_sprite *spr, int img_num)
{
	t_render_tex	r;

	if (draw_slice_init(c, spr, &r, img_num) == EXIT_FAILURE)
		return ;
	r.ymax = r.y0 + r.height;
	r.ftex_yinc = 0.79 * TEX_SCALE / (double)r.height;
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
		r.pixel = get_pixel(r.tex, r.tex_x, r.tex_y);
		if (r.pixel & 0xffffff)
			put_pixel(&c->mlx.mlx_img, spr->column, r.y,
				get_shaded_color(r.pixel, r.shade));
		r.ftex_y += r.ftex_yinc;
		r.y++;
	}
}
