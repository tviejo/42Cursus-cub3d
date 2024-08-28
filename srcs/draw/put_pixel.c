/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:42:42 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/08/28 15:49:31 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ads_gfx.h"

void	img_put_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->pixels + (y * img->line_size + x * (img->bpp >> 3));
	*(unsigned int *)dst = color;
}

void	img_put_pixel32(t_image *img, int x, int y, int color)
{
	*(t_uint *)(img->pixels + y * img->line_size + 4 * x) = color;
}

void	img_put_pixel32_safe(t_image *img, t_uint x, t_uint y, int color)
{
	if (x < (t_uint)img->dim.width && y < (t_uint)img->dim.height)
		*(t_uint *)(img->pixels + y * img->line_size + 4 * x) = color;
}
