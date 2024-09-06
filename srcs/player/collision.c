/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:22:09 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/06 13:52:41 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_wall(t_cub3d *cub, int x, int y)
{
	const int	item = cub->map.m[y][x];

	if (item == '1' || item == 'C' || item == '9')
		return (true);
	return (false);
}

static bool	check_wall(t_cub3d *cub, t_pointd old_pos, int x, int y)
{
	if (is_wall(cub, x, y) == true)
	{
		if (is_wall(cub, x, (int)old_pos.y) == false)
			cub->player.pos.y = old_pos.y;
		else if (is_wall(cub, (int)old_pos.x, y) == false)
			cub->player.pos.x = old_pos.x;
		else
			cub->player.pos = old_pos;
		return (true);
	}
	else
		return (false);
}

t_pointd	collides_wall(t_cub3d *cub, t_pointd old_pos)
{
	const int	x = (int)cub->player.pos.x;
	const int	y = (int)cub->player.pos.y;

	check_wall(cub, old_pos, x, y);
	if ((int)(cub->player.pos.x + 0.05) != x)
		check_wall(cub, old_pos, x + 1, y);
	if ((int)(cub->player.pos.y + 0.05) != y)
		check_wall(cub, old_pos, x, y + 1);
	if ((int)(cub->player.pos.x - 0.05) != x)
		check_wall(cub, old_pos, x - 1, y);
	if ((int)(cub->player.pos.y - 0.05) != y)
		check_wall(cub, old_pos, x, y - 1);
	return (cub->player.pos);
}
