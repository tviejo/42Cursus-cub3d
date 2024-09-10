/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:41:19 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/10 12:51:22 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_game_state(t_cub3d *cub, t_page newstate)
{
	const t_page	oldstate = cub->game.page;

	if (MOUSE_SHOWHIDE)
	{
		if (oldstate != GAME_PAGE && newstate == GAME_PAGE)
			mlx_mouse_hide(cub->mlx.mlx_ptr, cub->mlx.win_ptr);
		if (oldstate == GAME_PAGE && newstate != GAME_PAGE)
			mlx_mouse_show(cub->mlx.mlx_ptr, cub->mlx.win_ptr);
	}
	cub->game.page = newstate;
	if (newstate == GAME_PAGE)
		play_sound(GOOD_LUCK, cub);
}

static void	reset_keys(t_cub3d *cub3d)
{
	cub3d->inputs.open = false;
	cub3d->inputs.k_open_1 = false;
	cub3d->inputs.k_open_2 = false;
	cub3d->inputs.shoot = false;
}

int	render(t_cub3d *cub3d)
{
	if (cub3d->game.page == LANDING_PAGE)
		render_landing_page(cub3d);
	else if (cub3d->game.page == GAME_PAGE)
		render_game_page(cub3d);
	else if (cub3d->game.page == GAME_OVER_PAGE)
		render_game_over_page(cub3d);
	else
		render_exit_page(cub3d);
	reset_keys(cub3d);
	return (EXIT_SUCCESS);
}
