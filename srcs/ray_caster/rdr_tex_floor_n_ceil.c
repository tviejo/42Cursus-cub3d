/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_tex_floor_n_ceil.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:14:41 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/17 16:41:24 by ade-sarr         ###   ########.fr       */
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

static inline int	get_shaded_color(int color, double shade)
{
	return (
		((int)(((color >> 16) & 255) * shade) << 16)
		+ ((int)(((color >> 8) & 255) * shade) << 8)
		+ (int)((color & 255) * shade));
}

void	render_floor_column(t_rdr_horiz_tex t)
{
	while (t.y < t.ymax)
	{
		t.floor_dist = t.h_eye / (t.y - t.img_h2);
		t.tx = t.pl_tx + t.tx_mul * t.floor_dist;
		t.ty = t.pl_ty - t.ty_mul * t.floor_dist;
		//shade = c->mlx.shade_table[(int)(SHADE_PER_DIST * floor_dist) & (SHADE_TABLE_SIZE - 1)];
		t.shade = LUM_FADE_DIST / (LUM_FADE_DIST + t.floor_dist * t.floor_dist);
		put_pixel(t.img_dst, t.x, t.y, get_shaded_color(
				get_pixel(t.texture, (int)t.tx & (TEX_SIZE - 1),
					(int)t.ty & (TEX_SIZE - 1)), t.shade));
		t.y++;
	}
}

void	render_ceil_column(t_rdr_horiz_tex t)
{
	while (t.y < t.ymax)
	{
		t.floor_dist = t.h_eye / (t.img_h2 - t.y);
		t.tx = t.pl_tx + t.tx_mul * t.floor_dist;
		t.ty = -t.pl_ty + t.ty_mul * t.floor_dist;
		//shade = c->mlx.shade_table[(int)(SHADE_PER_DIST * floor_dist) & (SHADE_TABLE_SIZE - 1)];
		t.shade = LUM_FADE_DIST / (LUM_FADE_DIST + t.floor_dist * t.floor_dist);
		put_pixel(t.img_dst, t.x, t.y, get_shaded_color(
				get_pixel(t.texture, (int)t.tx & (TEX_SIZE - 1),
					(int)t.ty & (TEX_SIZE - 1)), t.shade));
		t.y++;
	}
}
