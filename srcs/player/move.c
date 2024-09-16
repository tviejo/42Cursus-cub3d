/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:20:11 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/16 16:46:24 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	change_height_player(t_cub3d *cub, double height)
{
	if (cub->player.view_height == height)
	{
		cub->player.speed = 1.0;
		cub->player.view_height = PLAYER_HEIGHT_FACTOR * cub->mlx.mlx_img.dim.height;
	}
	else
	{
		if (height < 0)
			cub->player.speed = 0.6 - fabs(height
					/ cub->mlx.mlx_img.dim.height);
		else
			cub->player.speed = 1.0;
		cub->player.view_height = height;
	}
}

static void	translate_player(t_cub3d *cub, double x, double y)
{
	const double	speed_mul = (1.0 + (int)cub->inputs.run)
		* cub->player.speed;
	double			dist;
	static int		old_height = 0;
	static bool		sound_trigger = true;
	t_player *const	pl = &cub->player;

	dist = cub->game.frame_time * TRANS_SPEED;
	pl->walk_distance += dist;
	pl->walk_height_shift = speed_mul * WALK_HEIGHT_RANGE * sin(pl->walk_distance * 7.0);
	if (pl->walk_height_shift > old_height && sound_trigger)
	{
		sound_trigger = false;
		old_height = pl->walk_height_shift;
		play_sound(SND_STEP, cub);
	}
	else if (pl->walk_height_shift < old_height)
		sound_trigger = true;
	dist *= speed_mul;
	pl->pos.x += dist * x;
	pl->pos.y -= dist * y;
}

static void	translation(t_cub3d *cub)
{
	t_player *const	pl = &cub->player;

	if (cub->inputs.mv_left)
		translate_player(cub, cos(pl->dir + M_PI_2), sin(pl->dir + M_PI_2));
	if (cub->inputs.mv_right)
		translate_player(cub, cos(pl->dir - M_PI_2), sin(pl->dir - M_PI_2));
	if (cub->inputs.mv_forward)
		translate_player(cub, cos(pl->dir), sin(pl->dir));
	if (cub->inputs.mv_backward)
		translate_player(cub, -cos(pl->dir), -sin(pl->dir));
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
	mouse_move(cub);
	rotation(cub);
	translation(cub);
	collides_wall(cub, old_pos);
	return (0);
}
