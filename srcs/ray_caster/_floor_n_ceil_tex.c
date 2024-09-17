/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _floor_n_ceil_tex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 01:43:33 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/17 16:43:23 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
static inline void	put_pixel(t_image *img, int x, int y, int color)
{
	*(t_uint *)(img->pixels + y * img->line_size + 4 * x) = color;
}

static inline int	get_pixel(t_image *img, int x, int y)
{
	return (*(t_uint *)(img->pixels + y * img->line_size + 4 * x));
}

static inline int	get_shaded_color(int color, double shade)
{
	return (
		((int)(((color >> 16) & 255) * shade) << 16)
		+ ((int)(((color >> 8) & 255) * shade) << 8)
		+ (int)((color & 255) * shade));
}

static int	init_fnc_textured(t_cub3d *c, t_render_horiz_tex *r, int line,
								double sens)
{
	const double	img_h2 = 0.5 * c->mlx.mlx_img.dim.height;

	if (sens == 1)
		r->tex = &c->mlx.text[TXID_CEIL];
	else
		r->tex = &c->mlx.text[TXID_FLOOR];
	if (r->tex->ptr == NULL)
		return (EXIT_FAILURE);
	r->dist = (sens * (c->player.view_height + c->player.walk_height_shift)
			- img_h2 * c->map.wall_heightscale) / (line - img_h2);
	r->shade = LUM_FADE_DIST / (LUM_FADE_DIST + r->dist * r->dist);
	r->scale = c->map.wall_heightscale * c->mlx.mlx_img.dim.height / r->dist;
	r->tex_modulo_m1 = TEX_SIZE - 1;
	r->angle = c->player.dir;
	return (EXIT_SUCCESS);
}

void	render_fnc_textured(t_cub3d *c, int line, int sens)
{
	t_render_horiz_tex	r;

	if (init_fnc_textured(c, &r, line, sens) == EXIT_FAILURE)
		return ;
	r.x0 = 0;
	r.xmax = c->mlx.mlx_img.dim.width;
	r.ftex_xinc = cos(r.angle) * TEX_SCALE / (double)r.scale;
	r.ftex_yinc = sin(r.angle) * TEX_SCALE / (double)r.scale;
	r.ftex_x = (line / (double)c->mlx.mlx_img.dim.height) * cos(r.angle)
		* c->player.pos.x * TEX_SCALE;
	r.ftex_y = (line / (double)c->mlx.mlx_img.dim.height) * sin(r.angle)
		* c->player.pos.y * TEX_SCALE;
	r.x = r.x0;
	while (r.x < r.xmax)
	{
		r.tex_x = (int)r.ftex_x & r.tex_modulo_m1;
		r.tex_y = (int)r.ftex_y & r.tex_modulo_m1;
		put_pixel(&c->mlx.mlx_img, r.x, line, get_shaded_color(
				get_pixel(r.tex, r.tex_x, r.tex_y), r.shade));
		r.ftex_x += r.ftex_xinc;
		r.ftex_y += r.ftex_yinc;
		r.x++;
	}
}

void	draw_floor_n_ceil_textured(t_cub3d *c)
{
	int		y;
	int		ymax;

	y = 0;
	ymax = (c->mlx.mlx_img.dim.height >> 1) - 1;
	while (y < ymax)
	{
		render_fnc_textured(c, y, 1);
		y++;
	}
	y = ymax + 1;
	ymax = c->mlx.mlx_img.dim.height - 1;
	while (y < ymax)
	{
		render_fnc_textured(c, y, -1);
		y++;
	}
}
*/