/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:20:11 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/28 17:18:00 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	open_door(t_cub3d *cub3d, int i, int j)
{
	cub3d->map.m[i][j] = 'O';
	return (0);
}

static bool	wall(t_cub3d *cub3d)
{
	const int	x = (int)cub3d->player.x;
	const int	y = (int)cub3d->player.y;
	const int	map_xy = cub3d->map.m[x][y];

	if (map_xy == '1' || map_xy == 'C')
	{
		if (map_xy == 'C' && cub3d->inputs.open)
			open_door(cub3d, x, y);
		else
			return (true);
	}
	return (false);
}

static void	translation(t_cub3d *cub3d)
{
	if (cub3d->inputs.mv_forward)
	{
		cub3d->player.x -= cos(cub3d->player.dir) * TRANS_SPEED;
		cub3d->player.y -= sin(cub3d->player.dir) * TRANS_SPEED;
	}
	if (cub3d->inputs.mv_backward)
	{
		cub3d->player.x += cos(cub3d->player.dir) * TRANS_SPEED;
		cub3d->player.y += sin(cub3d->player.dir) * TRANS_SPEED;
	}
	if (cub3d->inputs.mv_left)
	{
		cub3d->player.x += cos(cub3d->player.dir - M_PI_2) * TRANS_SPEED;
		cub3d->player.y += sin(cub3d->player.dir - M_PI_2) * TRANS_SPEED;
	}
	if (cub3d->inputs.mv_right)
	{
		cub3d->player.x += cos(cub3d->player.dir + M_PI_2) * TRANS_SPEED;
		cub3d->player.y += sin(cub3d->player.dir + M_PI_2) * TRANS_SPEED;
	}
}

/*static void	rotation(t_cub3d *cub3d)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, &x, &y);
	if (y - cub3d->inputs.mouse_y < 10)
		cub3d->player.dir -= (y - cub3d->inputs.mouse_y) * 0.05;
	cub3d->inputs.mouse_x = x;
	cub3d->inputs.mouse_y = y;
	if (cub3d->inputs.turn_left)
		cub3d->player.dir += ROT_SPEED;
	if (cub3d->inputs.turn_right)
		cub3d->player.dir -= ROT_SPEED;
}*/

static void	rotation(t_cub3d *cub3d)
{
	if (cub3d->inputs.turn_left)
		cub3d->player.dir += ROT_SPEED;
	if (cub3d->inputs.turn_right)
		cub3d->player.dir -= ROT_SPEED;
}

int	update_player_pos(t_cub3d *cub3d)
{
	double	old_pos_x;
	double	old_pos_y;

	old_pos_x = cub3d->player.x;
	old_pos_y = cub3d->player.y;
	rotation(cub3d);
	translation(cub3d);
	if (wall(cub3d))
	{
		cub3d->player.x = old_pos_x;
		cub3d->player.y = old_pos_y;
	}
	return (0);
}
