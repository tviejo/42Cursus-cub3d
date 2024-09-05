/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:22:09 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/05 14:59:19 by tviejo           ###   ########.fr       */
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
t_pointd	collides_wall(t_cub3d *cub, t_pointd old_pos)
{
	const int x = (int)cub->player.pos.x;
	const int y = (int)cub->player.pos.y;

	if (is_wall(cub, x, y) == true)
	{
		if (is_wall(cub, x, (int)old_pos.y) == false)
			cub->player.pos.y = old_pos.y;
		else if (is_wall(cub, (int)old_pos.x, y) == false)
			cub->player.pos.x = old_pos.x;
		else
			cub->player.pos = old_pos;
	}
	return (cub->player.pos);
}