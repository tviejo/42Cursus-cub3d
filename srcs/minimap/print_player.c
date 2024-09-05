/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:31:38 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/05 18:50:52 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_player(t_cub3d *cub)
{
	const t_pt2d	p0 = (t_pt2d){.x = 150, .y = 150, .color = COL_RED};
	t_pt2d			p1;
	int				x;
	int				y;

	x = -cub->game.minimap_size / 3;
	while (x < cub->game.minimap_size / 3)
	{
		y = -cub->game.minimap_size / 3;
		while (y < cub->game.minimap_size / 3)
		{
			img_put_pix32_safe(&cub->mlx.mlx_img, p0.x + x, p0.y + y, COL_RED);
			y++;
		}
		x++;
	}
	p1 = (t_pt2d){.x = p0.x + cub->game.minimap_size * cos(cub->player.dir),
		.y = p0.y - cub->game.minimap_size * sin(cub->player.dir)};
	draw_line(&cub->mlx.mlx_img, p0, p1);
}
