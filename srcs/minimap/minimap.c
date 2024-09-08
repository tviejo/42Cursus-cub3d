/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:07:14 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/08 17:12:40 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_map(t_cub3d *cub)
{
	t_point	pos;

	pos.y = cub->player.pos.y - 20;
	if (pos.y < 0)
		pos.y = 0;
	while (pos.y < cub->map.height + 1 && pos.y < cub->player.pos.y + 20)
	{
		pos.x = cub->player.pos.x - 20;
		if (pos.x < 0)
			pos.x = 0;
		while (pos.x < cub->map.width && pos.x < cub->player.pos.x + 20)
		{
			print_wall(cub, pos);
			pos.x++;
		}
		pos.y++;
	}
}

int	draw_minimap(t_cub3d *cub)
{
	print_map_border(cub, (t_point){{150}, {150}}, 100, COL_BLACK);
	print_map(cub);
	print_player(cub);
	print_monster(cub);
	return (EXIT_SUCCESS);
}
