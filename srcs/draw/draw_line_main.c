/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 02:41:50 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/08/28 17:21:58 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ads_gfx.h"

bool	is_obviously_outside(t_fdfmap *map, t_image *img,
			t_pt2d *p0, t_pt2d *p1)
{
	return ((p0->x >= img->dim.width && p1->x >= img->dim.width)
		|| (p0->x < 0 && p1->x < 0)
		|| (p0->y >= img->dim.height && p1->y >= img->dim.height)
		|| (p0->y < 0 && p1->y < 0)
		|| (map->has_perspective && map->z_clipping
			&& (p0->z > 0 || p1->z > 0))
	);
}

bool	clip_vertical(t_image *img, int x, t_pt2d *p0, t_pt2d *p1)
{
	double	a;
	double	b;
	int		y;

	if (p0->x == p1->x)
		return (false);
	a = (0.0 + p0->y - p1->y) / (p0->x - p1->x);
	b = p0->y - a * p0->x;
	y = a * x + b;
	if (y >= 0 && y < img->dim.height)
	{
		p0->x = x;
		p0->y = y;
		return (true);
	}
	return (false);
}

bool	clip_horizontal(t_image *img, int y, t_pt2d *p0, t_pt2d *p1)
{
	double	a;
	double	b;
	int		x;

	if (p0->y == p1->y)
		return (false);
	if (p0->x == p1->x)
		x = p0->x;
	else
	{
		a = (0.0 + p0->y - p1->y) / (p0->x - p1->x);
		b = p0->y - a * p0->x;
		x = (y - b) / a;
	}
	if (x >= 0 && x < img->dim.width)
	{
		p0->x = x;
		p0->y = y;
		return (true);
	}
	return (false);
}

bool	clip_seg_point(t_image *img, t_pt2d *p0, t_pt2d *p1)
{
	if (p0->x >= 0 && p0->x < img->dim.width
		&& p0->y >= 0 && p0->y < img->dim.height)
		return (true);
	if (p0->x < 0 && clip_vertical(img, 0, p0, p1))
		return (true);
	if (p0->x >= img->dim.width
		&& clip_vertical(img, img->dim.width - 1, p0, p1))
		return (true);
	if (p0->y < 0 && clip_horizontal(img, 0, p0, p1))
		return (true);
	if (p0->y >= img->dim.height
		&& clip_horizontal(img, img->dim.height - 1, p0, p1))
		return (true);
	return (false);
}

void	draw_line(t_fdfmap *map, t_image *img, t_pt2d p0, t_pt2d p1)
{
	if (is_obviously_outside(map, img, &p0, &p1))
		return ;
	if (!clip_seg_point(img, &p0, &p1))
		return ;
	if (!clip_seg_point(img, &p1, &p0))
		return ;
	if (map->use_z_color_palette)
	{
		map->pal_zrange = (p1.z0 - p0.z0) * map->palnbc_div_zrange;
		map->palidx0 = map->palrotbase
			+ (p0.z0 - map->range.zmin) * map->palnbc_div_zrange;
		draw_line_palette(map, img, &p0, &p1);
	}
	else
		draw_line_color(img, &p0, &p1);
}
