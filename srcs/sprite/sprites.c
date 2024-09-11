/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:28:37 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/11 02:04:25 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
void	copy_image_rect(t_image *dstimg, t_point dstpos, t_image *srcimg)
{
	t_point	dst;
	t_point	src;
	int		pixel;

	dst.x = pos.x - tex->dim.width;
	while (dst.x < pos.x)
	{
		src.x = dst.x - (pos.x - tex->dim.width);
		dst.y = pos.y - tex->dim.height ;
		while (dst.y < pos.y)
		{
			src.y = dst.y - (pos.y - tex->dim.height);
			pixel = *(int *)(tex->pixels + src.y * tex->line_size + src.x * 4);
			if (pixel & 255)
				put_pixel(&cub->mlx.mlx_img, dst.x, dst.y, pixel);
			dst.y++;
		}
		dst.x++;
	}
}

void	copy_image_rect(t_image *dstimg, t_point dstpos,
						t_image *srcimg, t_rect srcrect)
{

}

void	draw_monsters(t_cub3d *cub)
{
	static t_monsters	*monsters[MAX_MONSTERS];
	t_monsters			*m;
	t_pointd			ppos = cub->player.pos;
	int					i;

	i = 0;
	m = cub->monsters;
	while (m)
	{
		m->dist2_to_player = (m->pos.x - ppos.x) * (m->pos.x - ppos.x)
			+ (m->pos.y - ppos.y) * (m->pos.y - ppos.y);
		monsters[i++] = m;
		m = m->next;
	}
	quicksort(monsters, cub->nb_monsters);
	while ()
}
*/
