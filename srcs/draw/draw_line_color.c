/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:10:07 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/08/28 15:50:34 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ads_gfx.h"

void	draw_h_line_color(t_image *img, t_pt2d p0, t_pt2d p1)
{
	int				x;
	int				incx;
	const char		*pline = img->pixels + p0.y * img->line_size;
	const double	_1_dx = 1.0 / (p1.x - p0.x);

	incx = 1;
	if (p1.x < p0.x)
		incx = -1;
	x = p0.x;
	while (x != p1.x + incx)
	{
		*(t_uint *)(pline + 4 * x)
			= get_inter_color(p0.color, p1.color, (x - p0.x) * _1_dx);
		x += incx;
	}
}

void	draw_v_line_color(t_image *img, t_pt2d p0, t_pt2d p1)
{
	int				y;
	int				incy;
	const char		*pcol = img->pixels + 4 * p0.x;
	const double	_1_dy = 1.0 / (p1.y - p0.y);

	incy = 1;
	if (p1.y < p0.y)
		incy = -1;
	y = p0.y;
	while (y != p1.y + incy)
	{
		*(t_uint *)(pcol + y * img->line_size)
			= get_inter_color(p0.color, p1.color, (y - p0.y) * _1_dy);
		y += incy;
	}
}

void	draw_near_h_line_color(t_image *img, t_pt2d p0, t_pt2d p1,
			t_size2i delta)
{
	const int			slope = 2 * delta.y;
	const int			error_inc = -2 * delta.x;
	t_draw_line_vars	v;
	double				_1_dx;

	v.inc = (t_size2i){{1}, {1}};
	if (p1.x < p0.x)
		v.inc.x = -1;
	if (p1.y < p0.y)
		v.inc.y = -1;
	v.pt = (t_point){{p0.x}, {p0.y}};
	v.error = -delta.x;
	_1_dx = v.inc.x / (double)delta.x;
	while (v.pt.x != p1.x + v.inc.x)
	{
		*(t_uint *)(img->pixels + v.pt.y * img->line_size + 4 * v.pt.x)
			= get_inter_color(p0.color, p1.color, (v.pt.x - p0.x) * _1_dx);
		v.error += slope;
		if (v.error >= 0)
		{
			v.pt.y += v.inc.y;
			v.error += error_inc;
		}
		v.pt.x += v.inc.x;
	}
}

void	draw_near_v_line_color(t_image *img, t_pt2d p0, t_pt2d p1,
			t_size2i delta)
{
	const int			slope = 2 * delta.x;
	const int			error_inc = -2 * delta.y;
	t_draw_line_vars	v;
	double				_1_dy;

	v.inc = (t_size2i){{1}, {1}};
	if (p1.x < p0.x)
		v.inc.x = -1;
	if (p1.y < p0.y)
		v.inc.y = -1;
	v.pt = (t_point){{p0.x}, {p0.y}};
	v.error = -delta.y;
	_1_dy = v.inc.y / (double)delta.y;
	while (v.pt.y != p1.y + v.inc.y)
	{
		*(t_uint *)(img->pixels + v.pt.y * img->line_size + 4 * v.pt.x)
			= get_inter_color(p0.color, p1.color, (v.pt.y - p0.y) * _1_dy);
		v.error += slope;
		if (v.error >= 0)
		{
			v.pt.x += v.inc.x;
			v.error += error_inc;
		}
		v.pt.y += v.inc.y;
	}
}

void	draw_line_color(t_image *img, t_pt2d *p0, t_pt2d *p1)
{
	int	dx;
	int	dy;

	dx = p1->x - p0->x;
	dy = p1->y - p0->y;
	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;
	if (dy == 0)
		draw_h_line_color(img, *p0, *p1);
	else if (dx == 0)
		draw_v_line_color(img, *p0, *p1);
	else if (dx >= dy)
		draw_near_h_line_color(img, *p0, *p1, (t_size2i){{dx}, {dy}});
	else
		draw_near_v_line_color(img, *p0, *p1, (t_size2i){{dx}, {dy}});
}
