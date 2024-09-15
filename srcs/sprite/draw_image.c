/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:38:17 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/15 19:09:14 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline static void	put_pixel(t_image *img, int x, int y, int color)
{
	*(t_uint *)(img->pixels + y * img->line_size + 4 * x) = color;
}

void	draw_image_autoscale(t_image *src, t_image *dst)
{
	t_draw_img	di;
	double		scale;

	di.srcimg = src;
	di.dstimg = dst;
	di.scale = dst->dim.width / (double)src->dim.width;
	scale = dst->dim.height / (double)src->dim.height;
	if (scale < di.scale)
		di.scale = scale;
	di.srcpos.x = di.srcimg->dim.width >> 1;
	di.srcpos.y = di.srcimg->dim.height >> 1;
	di.dstpos.x = di.dstimg->dim.width >> 1;
	di.dstpos.y = di.dstimg->dim.height >> 1;
	draw_image(di);
}

/*void	draw_image_init(t_draw_img *di)
{
	;
}*/

/* Attention: pour l'intant aucun test ni clipping n'est appliqué !
*/
void	draw_image(t_draw_img di)
{
	di.inc = 1.0 / di.scale;
	di.src_x0 = 0.0;
	di.src_y = 0.0;
	di.srci_y = 0;
	di.dst_x0 = di.dstpos.x - di.srcpos.x * di.scale;
	di.dst.y = di.dstpos.y - di.srcpos.y * di.scale;
	di.dstmax.x = di.dst_x0 + di.srcimg->dim.width * di.scale;
	di.dstmax.y = di.dst.y + di.srcimg->dim.height * di.scale;
	while (di.dst.y < di.dstmax.y)
	{
		di.src_x = di.src_x0;
		di.dst.x = di.dst_x0 - 1;
		while (++di.dst.x < di.dstmax.x)
		{
			di.pixel = *(int *)(di.srcimg->pixels
					+ di.srci_y * di.srcimg->line_size + (int)di.src_x * 4);
			if (!(di.pixel & 0xff000000))
				put_pixel(di.dstimg, di.dst.x, di.dst.y, di.pixel);
			di.src_x += di.inc;
		}
		di.dst.y++;
		di.src_y += di.inc;
		di.srci_y = di.src_y;
	}
}
