/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:27:13 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/10 13:37:11 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	difficulty_keys(t_cub3d *cub3d, int keycode)
{
	if (keycode == k_zoom_out && cub3d->game.page == LANDING_PAGE)
	{
		if (cub3d->game.dificulty > 20)
			cub3d->game.dificulty = 20;
		else
			cub3d->game.dificulty++;
	}
	if (keycode == k_zoom_in && cub3d->game.page == LANDING_PAGE)
	{
		cub3d->game.dificulty--;
		if (cub3d->game.dificulty <= 0)
			cub3d->game.dificulty = 0;
	}
}

void	minimap_keys(t_cub3d *cub3d, int keycode)
{
	if (keycode == k_zoom_out && cub3d->game.page == GAME_PAGE)
	{
		if (cub3d->game.minimap_size > 60)
			cub3d->game.minimap_size = 60;
		else
			cub3d->game.minimap_size++;
	}
	if (keycode == k_zoom_in && cub3d->game.page == GAME_PAGE)
	{
		if (cub3d->game.minimap_size < 2)
			cub3d->game.minimap_size = 2;
		cub3d->game.minimap_size--;
	}
}

void	key_release_player_2(int keycode, t_cub3d *cub)
{
	if (keycode == k_reload && cub->player.ammo < 10)
		cub->inputs.reload = true;
	if (keycode == k_sit && cub->game.page == GAME_PAGE)
		change_height_player(cub, -0.2 * cub->mlx.mlx_img.dim.height);
	if (keycode == k_lie_down && cub->game.page == GAME_PAGE)
		change_height_player(cub, -0.4 * cub->mlx.mlx_img.dim.height);
}
