/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_monster.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:08:25 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/12 11:26:12 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline static void	put_pixel(t_image *img, int x, int y, int color)
{
	*(t_uint *)(img->pixels + y * img->line_size + 4 * x) = color;
}

inline static bool	is_inside_circle(int x, int y)
{
	return (x * x + y * y < 10000);
}

/*
static int	print_square_monster(t_image *img, t_point pos, int color,
		t_cub3d *cub)
{
	int	x;
	int	y;

	x = cub->game.minimap_size / 4;
	while (x < cub->game.minimap_size * 0.75)
	{
		y = cub->game.minimap_size / 4;
		while (y < cub->game.minimap_size * 0.75 )
		{
			if (is_inside_circle(pos.x * cub->game.minimap_size + x, pos.y
					* cub->game.minimap_size + y, cub) == true)
				img_put_pix32_safe(img, 150 + pos.x * cub->game.minimap_size + x
					- (cub->player.pos.x * cub->game.minimap_size), 150 + pos.y
					* cub->game.minimap_size + y - (cub->player.pos.y
						* cub->game.minimap_size), color);
			y++;
		}
		x++;
	}
	return (EXIT_SUCCESS);
}
*/

void	print_monsters(t_cub3d *cub)
{
	t_monsters	*m;
	int			i;
	int			j;
	t_point		p0;
	t_point		p0c;

	m = cub->monsters;
	while (m)
	{
		p0.x = (m->pos.x - cub->player.pos.x) * cub->game.minimap_size;
		p0.y = (m->pos.y - cub->player.pos.y) * cub->game.minimap_size;
		p0c.x = p0.x + cub->game.minimap_center.x;
		p0c.y = p0.y + cub->game.minimap_center.y;
		i = -2;
		while (++i <= 1)
		{
			j = -2;
			while (++j <= 1)
				if (is_inside_circle(p0.x + i, p0.y + j))
					put_pixel(&cub->mlx.mlx_img, p0c.x + i, p0c.y + j, COL_RED);
		}
		m = m->next;
	}
}

					/*if (is_inside_circle(m->pos.x * cub->game.minimap_size + i,
						m->pos.y * cub->game.minimap_size + i))
					put_pixel(&cub->mlx.mlx_img, 150 + m->pos.x
						* cub->game.minimap_size + i - (cub->player.pos.x
							* cub->game.minimap_size), 150 + m->pos.y
						* cub->game.minimap_size + j - (cub->player.pos.y
							* cub->game.minimap_size), COL_RED);*/