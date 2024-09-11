/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_tex_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 03:47:02 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/10 23:22:34 by ade-sarr         ###   ########.fr       */
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

inline int	get_shaded_color(int color, double shade, int item)
{
	if (item == 'C')
		return (color);
	return (
		((int)(((color >> 16) & 255) * shade) << 16)
		+ ((int)(((color >> 8) & 255) * shade) << 8)
		+ (int)((color & 255) * shade));
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
}
