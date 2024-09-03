/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:20:11 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/03 05:53:24 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	open_door(t_cub3d *cub, int x, int y)
{
	cub->map.m[y][x] = 'O';
	return (0);
}

static bool	collides_wall(t_cub3d *cub)
{
	const int	x = (int)cub->player.pos.x;
	const int	y = (int)cub->player.pos.y;
	const int	item = cub->map.m[y][x];

	if (item == '1' || item == 'C')
	{
		if (item == 'C' && cub->inputs.open)
			open_door(cub, x, y);
		else
			return (true);
	}
	return (false);
}

static void	translation(t_cub3d *cub)
{
	t_player *const	pl = &cub->player;
	double			dist;

	dist = cub->game.frame_time * TRANS_SPEED * (1.0 + (int)cub->inputs.run);
	if (cub->inputs.mv_left)
	{
		pl->pos.x += dist * cos(pl->dir + M_PI_2);
		pl->pos.y -= dist * sin(pl->dir + M_PI_2);
	}
	if (cub->inputs.mv_right)
	{
		pl->pos.x += dist * cos(pl->dir - M_PI_2);
		pl->pos.y -= dist * sin(pl->dir - M_PI_2);
	}
	if (cub->inputs.mv_forward)
	{
		pl->pos.x += dist * cos(pl->dir);
		pl->pos.y -= dist * sin(pl->dir);
	}
	if (cub->inputs.mv_backward)
	{
		pl->pos.x -= dist * cos(pl->dir);
		pl->pos.y += dist * sin(pl->dir);
	}
}

/*static void	rotation(t_cub3d *cub)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(cub->mlx.mlx_ptr, cub->mlx.win_ptr, &x, &y);
	if (y - cub->inputs.mouse_y < 10)
		rotate_player(&cub->player, (y - cub->inputs.mouse_y) * 0.05);
	cub->inputs.mouse_x = x;
	cub->inputs.mouse_y = y;
	if (cub->inputs.turn_left)
		rotate_player(&cub->player, ROT_SPEED);
	if (cub->inputs.turn_right)
		rotate_player(&cub->player, -ROT_SPEED);
}*/

static void	rotation(t_cub3d *cub)
{
	double	rot_angle;

	rot_angle = cub->game.frame_time * ROT_SPEED * (1.0 + (int)cub->inputs.run);
	if (cub->inputs.turn_left)
		rotate_player(&cub->player, rot_angle);
	if (cub->inputs.turn_right)
		rotate_player(&cub->player, -rot_angle);
}

int	update_player_pos(t_cub3d *cub)
{
	t_pointd	old_pos;

	old_pos = cub->player.pos;
	rotation(cub);
	translation(cub);
	if (collides_wall(cub))
		cub->player.pos = old_pos;
	return (0);
}
