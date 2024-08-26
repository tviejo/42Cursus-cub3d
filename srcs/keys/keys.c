/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:24:17 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/26 15:46:08 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


int init_keys(t_cub3d *cub3d)
{
	cub3d->keys.up = false;
	cub3d->keys.down = false;
	cub3d->keys.left = false;
	cub3d->keys.right = false;
	cub3d->keys.turn_left = false;
	cub3d->keys.turn_right = false;
	return (0);
}
int	key_press(int keycode, t_cub3d *cub3d)
{
	if ((keycode == XK_Escape || keycode == XK_y)
		&& cub3d->game.page == EXIT_PAGE)
		ft_close(cub3d);
	if (keycode == XK_Escape)
		cub3d->game.page = EXIT_PAGE;
	if (keycode == XK_w)
		cub3d->keys.up = true;
	if (keycode == XK_s)
		cub3d->keys.down = true;
	if (keycode == XK_a)
		cub3d->keys.left = true;
	if (keycode == XK_d)
		cub3d->keys.right = true;
	if (keycode == XK_Left)
		cub3d->keys.turn_left = true;
	if (keycode == XK_Right)
		cub3d->keys.turn_right = true;
	if (keycode == XK_space && cub3d->game.page == LANDING_PAGE)
		cub3d->game.page = GAME_PAGE;
	if (keycode == XK_n && cub3d->game.page == EXIT_PAGE)
		cub3d->game.page = GAME_PAGE;
	return (0);
}

int	key_release(int keycode, t_cub3d *cub3d)
{
	if (keycode == XK_w)
		cub3d->keys.up = false;
	if (keycode == XK_s)
		cub3d->keys.down = false;
	if (keycode == XK_a)
		cub3d->keys.left = false;
	if (keycode == XK_d)
		cub3d->keys.right = false;
	if (keycode == XK_Left)
		cub3d->keys.turn_left = false;
	if (keycode == XK_Right)
		cub3d->keys.turn_right = false;
	return (0);
}