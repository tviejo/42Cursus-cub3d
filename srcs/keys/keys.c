/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:24:17 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/03 05:19:52 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_player_inputs(t_player_inputs *in)
{
	const bool	strafe = in->strafe_mode ^ in->strafe_alt;

	in->mv_forward = in->k_up_1 || in->k_up_2;
	in->mv_backward = in->k_down_1 || in->k_down_2;
	in->mv_left = strafe && (in->k_left_1 || in->k_left_2);
	in->mv_right = strafe && (in->k_right_1 || in->k_right_2);
	in->turn_left = !strafe && (in->k_left_1 || in->k_left_2);
	in->turn_right = !strafe && (in->k_right_1 || in->k_right_2);
	in->open = in->k_open_1 || in->k_open_2;
	in->run = in->k_run;
}

void	key_press_player(int keycode, t_player_inputs *in)
{
	if (keycode == k_up_1)
		in->k_up_1 = true;
	if (keycode == k_up_2)
		in->k_up_2 = true;
	if (keycode == k_down_1)
		in->k_down_1 = true;
	if (keycode == k_down_2)
		in->k_down_2 = true;
	if (keycode == k_left_1)
		in->k_left_1 = true;
	if (keycode == k_left_2)
		in->k_left_2 = true;
	if (keycode == k_right_1)
		in->k_right_1 = true;
	if (keycode == k_right_2)
		in->k_right_2 = true;
	if (keycode == k_open_1)
		in->k_open_1 = true;
	if (keycode == k_open_2)
		in->k_open_2 = true;
	if (keycode == k_fire_1)
		in->k_fire_1 = true;
	if (keycode == k_fire_2)
		in->k_fire_2 = true;
}

int	key_press(int keycode, t_cub3d *cub3d)
{
	if ((keycode == XK_Escape || keycode == XK_y)
		&& cub3d->game.page == EXIT_PAGE)
		ft_close(cub3d, NULL);
	if (keycode == XK_Escape)
		cub3d->game.page = EXIT_PAGE;
	if (keycode == XK_space && cub3d->game.page == LANDING_PAGE)
		cub3d->game.page = GAME_PAGE;
	if (keycode == XK_n && cub3d->game.page == EXIT_PAGE)
		cub3d->game.page = GAME_PAGE;
	if (keycode == k_strafe_alt)
		cub3d->inputs.strafe_alt = true;
	if (keycode == k_run)
		cub3d->inputs.k_run = true;
	key_press_player(keycode, &cub3d->inputs);
	update_player_inputs(&cub3d->inputs);
	return (0);
}

void	key_release_player(int keycode, t_player_inputs *in)
{
	if (keycode == k_up_1)
		in->k_up_1 = false;
	if (keycode == k_up_2)
		in->k_up_2 = false;
	if (keycode == k_down_1)
		in->k_down_1 = false;
	if (keycode == k_down_2)
		in->k_down_2 = false;
	if (keycode == k_left_1)
		in->k_left_1 = false;
	if (keycode == k_left_2)
		in->k_left_2 = false;
	if (keycode == k_right_1)
		in->k_right_1 = false;
	if (keycode == k_right_2)
		in->k_right_2 = false;
	if (keycode == k_open_1)
		in->k_open_1 = false;
	if (keycode == k_open_2)
		in->k_open_2 = false;
	if (keycode == k_fire_1)
		in->k_fire_1 = false;
	if (keycode == k_fire_2)
		in->k_fire_2 = false;
}

int	key_release(int keycode, t_cub3d *cub3d)
{
	if (keycode == k_strafe_switch)
		cub3d->inputs.strafe_mode = !cub3d->inputs.strafe_mode;
	if (keycode == k_strafe_alt)
		cub3d->inputs.strafe_alt = false;
	if (keycode == k_run)
		cub3d->inputs.k_run = false;
	key_release_player(keycode, &cub3d->inputs);
	update_player_inputs(&cub3d->inputs);
	return (0);
}
