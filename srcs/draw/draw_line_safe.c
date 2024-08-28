/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_safe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:10:07 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/08/28 15:50:30 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ads_gfx.h"

void	draw_h_line_safe(t_image *img, t_pt2d p0, t_pt2d p1)
{
	int				x;
	int				incx;
	const double	_1_dx = 1.0 / (p1.x - p0.x);

	incx = 1;
	if (p1.x < p0.x)
		incx = -1;
	x = p0.x;
	while (x != p1.x + incx)
	{
		img_put_pixel32_safe(img, x, p0.y, get_inter_color(
				p0.color, p1.color, (x - p0.x) * _1_dx));
		x += incx;
	}
}

void	draw_v_line_safe(t_image *img, t_pt2d p0, t_pt2d p1)
{
	int				y;
	int				incy;
	const double	_1_dy = 1.0 / (p1.y - p0.y);

	incy = 1;
	if (p1.y < p0.y)
		incy = -1;
	y = p0.y;
	while (y != p1.y + incy)
	{
		img_put_pixel32_safe(img, p0.x, y, get_inter_color(
				p0.color, p1.color, (y - p0.y) * _1_dy));
		y += incy;
	}
}

void	draw_near_h_line_safe(t_image *img, t_pt2d p0, t_pt2d p1,
			t_size2i delta)
{
	const int	slope = 2 * delta.y;
	const int	error_inc = -2 * delta.x;
	int			error;
	t_size2i	inc;
	t_point		pt;

	inc = (t_size2i){{1}, {1}};
	if (p1.x < p0.x)
		inc.x = -1;
	if (p1.y < p0.y)
		inc.y = -1;
	pt = (t_point){{p0.x}, {p0.y}};
	error = -delta.x;
	while (pt.x != p1.x + inc.x)
	{
		img_put_pixel32_safe(img, pt.x, pt.y, get_inter_color(
				p0.color, p1.color, (pt.x - p0.x) * inc.x / (double)delta.x));
		error += slope;
		if (error >= 0)
		{
			pt.y += inc.y;
			error += error_inc;
		}
		pt.x += inc.x;
	}
}

void	draw_near_v_line_safe(t_image *img, t_pt2d p0, t_pt2d p1,
			t_size2i delta)
{
	const int	slope = 2 * delta.x;
	const int	error_inc = -2 * delta.y;
	int			error;
	t_size2i	inc;
	t_point		pt;

	inc = (t_size2i){{1}, {1}};
	if (p1.x < p0.x)
		inc.x = -1;
	if (p1.y < p0.y)
		inc.y = -1;
	pt = (t_point){{p0.x}, {p0.y}};
	error = -delta.y;
	while (pt.y != p1.y + inc.y)
	{
		img_put_pixel32_safe(img, pt.x, pt.y, get_inter_color(
				p0.color, p1.color, (pt.y - p0.y) * inc.y / (double)delta.y));
		error += slope;
		if (error >= 0)
		{
			pt.x += inc.x;
			error += error_inc;
		}
		pt.y += inc.y;
	}
}

void	draw_line_safe(t_image *img, t_pt2d p0, t_pt2d p1)
{
	int	dx;
	int	dy;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;
	if (dy == 0)
		draw_h_line_safe(img, p0, p1);
	else if (dx == 0)
		draw_v_line_safe(img, p0, p1);
	else if (dx >= dy)
		draw_near_h_line_safe(img, p0, p1, (t_size2i){{dx}, {dy}});
	else
		draw_near_v_line_safe(img, p0, p1, (t_size2i){{dx}, {dy}});
}
