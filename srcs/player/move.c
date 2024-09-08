/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:20:11 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/08 15:30:50 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	translate_player(t_cub3d *cub, double x, double y)
{
	const double			speed_mul = 1.0 + (int)cub->inputs.run;
	double					dist;
	t_player *const pl = &cub->player;
	static int old_height = 0;
	static bool print_sound = true;

	dist = cub->game.frame_time * TRANS_SPEED;
	pl->walk_distance += dist;
	pl->walk_height_shift = speed_mul * 20.0 * sin(pl->walk_distance * 7.0);
	if (pl->walk_height_shift > old_height && print_sound == true)
	{
		print_sound = false;
		old_height = pl->walk_height_shift;
		play_sound(STEP);
	}
	else if (pl->walk_height_shift < old_height)
		print_sound = true;
	dist *= speed_mul;
	pl->pos.x += dist * x;
	pl->pos.y -= dist * y;
}

static void	translation(t_cub3d *cub)
{
	t_player *const pl = &cub->player;
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
	//t_scaninfo	si;

	old_pos = cub->player.pos;
	mouse_move(cub);
	rotation(cub);
	translation(cub);
	collides_wall(cub, old_pos);
	/*if (cub->inputs.turn_left || cub->inputs.turn_right)
	{
		scan_in_front(cub, &si, 0.0);
		printf("scan_in_front(): %c [%i,%i] dist: %f\n",
			si.item, si.mpos.x, si.mpos.y, si.distance);
	}*/
	return (0);
}
