/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 00:26:16 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/08 00:58:08 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ads_gfx.h"

static bool	is_obviously_outside(t_image *img, t_rect *rc)
{
	return ((rc->x0 >= img->dim.width && rc->x1 >= img->dim.width)
		|| (rc->x0 < 0 && rc->x1 < 0)
		|| (rc->y0 >= img->dim.height && rc->y1 >= img->dim.height)
		|| (rc->y0 < 0 && rc->y1 < 0)
	);
}

static void	fill_rectangle_init(t_image *img, t_rect *rc)
{
	int	i;

	if (rc->y0 > rc->y1)
	{
		i = rc->y0;
		rc->y0 = rc->y1;
		rc->y1 = i;
	}
	if (rc->x0 > rc->x1)
	{
		i = rc->x0;
		rc->x0 = rc->x1;
		rc->x1 = i;
	}
	if (rc->x0 < 0)
		rc->x0 = 0;
	if (rc->y0 < 0)
		rc->y0 = 0;
	if (rc->x1 >= img->dim.width)
		rc->x1 = img->dim.width - 1;
	if (rc->y1 >= img->dim.height)
		rc->y1 = img->dim.height - 1;
}

void	fill_rectangle(t_image *img, t_rect rc, int color)
{
	int		x;
	int		rc_width;
	t_uint	*addr;
	int		nextline_step;

	if (is_obviously_outside(img, &rc))
		return ;
	fill_rectangle_init(img, &rc);
	rc_width = rc.x1 - rc.x0 + 1;
	nextline_step = (img->line_size >> 2) - rc_width;
	addr = (t_uint *)(img->pixels + rc.y0 * img->line_size + 4 * rc.x0);
	while (rc.y0 <= rc.y1)
	{
		x = rc_width;
		while (x--)
			*addr++ = color;
		rc.y0++;
		addr += nextline_step;
	}
}
