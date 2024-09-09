/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:22:09 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/09 16:36:13 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_wall(t_cub3d *cub, int x, int y)
{
	const int	item = cub->map.m[y][x];

	if (item == '1' || item == 'C' || item == '9')
		return (true);
	return (false);
}

static bool	find_wall(t_cub3d *cub, t_pointd pos, t_pointd new_pos,
		t_pointd old_pos)
{
	double	i;

	i = -0.02;
	while (i <= 0.02)
	{
		if (is_wall(cub, (int)(pos.x + i), (int)(pos.y - i)) == true)
		{
			if (is_wall(cub, new_pos.x, (int)old_pos.y) == false)
				cub->player.pos.y = old_pos.y;
			else if (is_wall(cub, (int)old_pos.x, new_pos.y) == false)
				cub->player.pos.x = old_pos.x;
			else
				cub->player.pos = old_pos;
			return (true);
		}
		i += 0.01;
	}
	return (false);
}

static int	find_wall_between_two_pos(t_cub3d *cub, t_pointd old_pos,
		t_pointd new_pos)
{
	t_pointd	inc;
	t_pointd	pos;
	int			i;

	inc.x = (new_pos.x - old_pos.x) / 100;
	inc.y = (new_pos.y - old_pos.y) / 100;
	pos = old_pos;
	i = 0;
	while (i < 100)
	{
		pos.x += inc.x;
		pos.y += inc.y;
		if (find_wall(cub, pos, new_pos, old_pos) == true)
			return (i);
		i++;
	}
	return (i);
}

// static int find_angle_from_pos(t_pointd pos, t_pointd new_pos)
// {
// 	const double	dx = new_pos.x - pos.x;
// 	const double	dy = new_pos.y - pos.y;
// 	const double	angle = atan2(dy, dx) * 180 / M_PI;

// 	return ((int)angle);
// }

t_pointd	collides_wall(t_cub3d *cub, t_pointd old_pos)
{
	find_wall_between_two_pos(cub, old_pos, cub->player.pos);
	return (cub->player.pos);
}
