/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_monster.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:08:25 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/07 13:18:14 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	print_monster(t_cub3d *cub)
{
	t_monsters	*tmp;
	int			i;
	int			j;

	tmp = cub->monsters;
	while (tmp)
	{
		i = -2;
		while (++i <= 1)
		{
			j = -2;
			while (++j <= 1)
			{
				if (is_inside_circle(tmp->pos.x * cub->game.minimap_size + i,
						tmp->pos.y * cub->game.minimap_size + i, cub) == true)
					img_put_pix32_safe(&cub->mlx.mlx_img, 150 + tmp->pos.x
						* cub->game.minimap_size + i - (cub->player.pos.x
							* cub->game.minimap_size), 150 + tmp->pos.y
						* cub->game.minimap_size + j - (cub->player.pos.y
							* cub->game.minimap_size), COL_RED);
			}
		}
		tmp = tmp->next;
	}
}
