/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_fast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:10:07 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/08/28 15:50:38 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ads_gfx.h"

void	draw_h_line(t_image *img, t_pt2d p0, t_pt2d p1)
{
	int	x;
	int	incx;

	incx = 1;
	if (p1.x < p0.x)
		incx = -1;
	x = p0.x;
	while (x != p1.x + incx)
	{
		*(t_uint *)(img->pixels + p0.y * img->line_size + 4 * x) = p0.color;
		x += incx;
	}
}

void	draw_v_line(t_image *img, t_pt2d p0, t_pt2d p1)
{
	int	y;
	int	incy;

	incy = 1;
	if (p1.y < p0.y)
		incy = -1;
	y = p0.y;
	while (y != p1.y + incy)
	{
		*(t_uint *)(img->pixels + y * img->line_size + 4 * p0.x) = p0.color;
		y += incy;
	}
}

void	draw_near_h_line(t_image *img, t_pt2d p0, t_pt2d p1, t_size2i delta)
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
		*(t_uint *)(img->pixels + pt.y * img->line_size + 4 * pt.x) = p0.color;
		error += slope;
		if (error >= 0)
		{
			pt.y += inc.y;
			error += error_inc;
		}
		pt.x += inc.x;
	}
}

void	draw_near_v_line(t_image *img, t_pt2d p0, t_pt2d p1, t_size2i delta)
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
		*(t_uint *)(img->pixels + pt.y * img->line_size + 4 * pt.x) = p0.color;
		error += slope;
		if (error >= 0)
		{
			pt.x += inc.x;
			error += error_inc;
		}
		pt.y += inc.y;
	}
}

void	draw_line_fast(t_image *img, t_pt2d p0, t_pt2d p1)
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
		draw_h_line(img, p0, p1);
	else if (dx == 0)
		draw_v_line(img, p0, p1);
	else if (dx >= dy)
		draw_near_h_line(img, p0, p1, (t_size2i){{dx}, {dy}});
	else
		draw_near_v_line(img, p0, p1, (t_size2i){{dx}, {dy}});
}
