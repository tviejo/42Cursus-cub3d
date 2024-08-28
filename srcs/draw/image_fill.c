/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:59:10 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/08/28 15:49:24 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ads_gfx.h"

void	img_clear(t_image *img)
{
	char		*p;
	u_int64_t	*p64;
	int			bytes;
	int			qwords;

	p64 = (u_int64_t *)img->pixels;
	bytes = img->line_size * img->dim.height;
	qwords = bytes >> 3;
	while (qwords--)
		*p64++ = 0L;
	p = (char *)p64;
	bytes &= 7;
	while (bytes--)
		*p++ = 0;
}

void	img_clear128(t_image *img)
{
	char		*p;
	__uint128_t	*p128;
	int			bytes;
	int			dqwords;

	p128 = (__uint128_t *)img->pixels;
	bytes = img->line_size * img->dim.height;
	dqwords = bytes >> 4;
	while (dqwords--)
		*p128++ = 0;
	p = (char *)p128;
	bytes &= 15;
	while (bytes--)
		*p++ = 0;
}

void	img_fill(t_image *img, int color)
{
	char		*p;
	int			bytes;
	int			qwords;
	u_int64_t	color64;
	u_int64_t	*p64;

	color64 = (unsigned int)color;
	color64 = (color64 << 32) + color64;
	p64 = (u_int64_t *)img->pixels;
	bytes = img->line_size * img->dim.height;
	qwords = bytes >> 3;
	while (qwords--)
		*p64++ = color64;
	p = (char *)p64;
	bytes &= 7;
	if (bytes >= 4)
	{
		*(int *)p = color;
		p += 4;
		bytes -= 4;
	}
	while (bytes--)
		*p++ = 0;
}

void	img_fill128(t_image *img, int color)
{
	char		*p;
	int			bytes;
	int			dqwords;
	__uint128_t	color128;
	__uint128_t	*p128;

	color128 = (unsigned int)color;
	color128 = (color128 << 96) + (color128 << 64)
		+ (color128 << 32) + color128;
	p128 = (__uint128_t *)img->pixels;
	bytes = img->line_size * img->dim.height;
	dqwords = bytes >> 4;
	while (dqwords--)
		*p128++ = color128;
	p = (char *)p128;
	bytes &= 15;
	while (bytes >= 4)
	{
		*(int *)p = color;
		p += 4;
		bytes -= 4;
	}
	while (bytes--)
		*p++ = 0;
}
