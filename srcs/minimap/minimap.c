/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:07:14 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/05 18:41:50 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_minimap(t_cub3d *cub)
{
	t_point	pos;

	print_map_border(cub, (t_point){{150}, {150}}, 100, COL_BLACK);
	pos.y = cub->player.pos.y - 10;
	if (pos.y < 0)
		pos.y = 0;
	while (pos.y < cub->map.height + 1 && pos.y < cub->player.pos.y + 10)
	{
		pos.x = cub->player.pos.x - 10;
		if (pos.x < 0)
			pos.x = 0;
		while (pos.x < cub->map.width && pos.x < cub->player.pos.x + 10)
		{
			print_wall(cub, pos);
			pos.x++;
		}
		pos.y++;
	}
	print_player(cub);
	return (EXIT_SUCCESS);
}
