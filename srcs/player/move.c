/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:20:11 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/03 14:40:23 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	collides_wall(cub, old_pos);
	return (0);
}
