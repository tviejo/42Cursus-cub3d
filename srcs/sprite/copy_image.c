/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:07:08 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/15 17:33:58 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline static void	put_pixel(t_image *img, int x, int y, int color)
{
	*(t_uint *)(img->pixels + y * img->line_size + 4 * x) = color;
}

/*void	copy_image_init_2(t_copy_img *ci, t_point *src, t_point *dst,
						t_point *srcmax)
{
	if (dst->x + ci->dim.x - 1 >= ci->dstimg->dim.x)
		ci->dim.x -= dst->x + ci->dim.x - ci->dstimg->dim.x;
	if (dst->y + ci->dim.y - 1 >= ci->dstimg->dim.y)
		ci->dim.y -= dst->y + ci->dim.y - ci->dstimg->dim.y;
	*srcmax = (t_point){.x = src->x + ci->dim.x, .y = src->y + ci->dim.y};
}*/

static bool	copy_image_clip(t_copy_img ci, t_point *src, t_point *dst,
						t_point *srcmax)
{
	*src = (t_point){.x = 0, .y = 0};
	dst->x = ci.dstpos.x - ci.srcpos.x;
	dst->y = ci.dstpos.y - ci.srcpos.y;
	ci.dim = ci.srcimg->dim;
	if (dst->x + ci.dim.x <= 0 || dst->x >= ci.dstimg->dim.x
		|| dst->y + ci.dim.y <= 0 || dst->y >= ci.dstimg->dim.y)
		return (false);
	if (dst->x < 0)
	{
		ci.dim.x += dst->x;
		src->x -= dst->x;
		dst->x = 0;
	}
	if (dst->y < 0)
	{
		ci.dim.y += dst->y;
		src->y -= dst->y;
		dst->y = 0;
	}
	if (dst->x + ci.dim.x - 1 >= ci.dstimg->dim.x)
		ci.dim.x -= dst->x + ci.dim.x - ci.dstimg->dim.x;
	if (dst->y + ci.dim.y - 1 >= ci.dstimg->dim.y)
		ci.dim.y -= dst->y + ci.dim.y - ci.dstimg->dim.y;
	*srcmax = (t_point){.x = src->x + ci.dim.x, .y = src->y + ci.dim.y};
	return (true);
}

void	copy_image(t_image *srcimg, t_point srcpos,
					t_image *dstimg, t_point dstpos)
{
	t_point			src;
	t_point			dst;
	t_point			srcmax;
	t_src_dst_x0	x0;
	int				pixel;

	if (!copy_image_clip((t_copy_img){srcimg, dstimg, srcpos, dstpos,
			{{0}, {0}}}, &src, &dst, &srcmax))
		return ;
	x0 = (t_src_dst_x0){.src = src.x, .dst = dst.x};
	while (src.y < srcmax.y)
	{
		src.x = x0.src - 1;
		dst.x = x0.dst;
		while (++src.x < srcmax.x)
		{
			pixel = *(int *)(srcimg->pixels + src.y * srcimg->line_size
					+ src.x * 4);
			if (!(pixel & 0xff000000))
				put_pixel(dstimg, dst.x, dst.y, pixel);
			dst.x++;
		}
		src.y++;
		dst.y++;
	}
}

/*
void	copy_image_rect(t_image *dstimg, t_point dstpos,
						t_image *srcimg, t_rect srcrect)
{

}*/
