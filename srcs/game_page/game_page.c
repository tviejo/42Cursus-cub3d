/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:22:41 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/09 22:08:40 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_game_page(t_cub3d *cub3d)
{
	update_player_pos(cub3d);
	update_health(cub3d);
	render_frame(cub3d);
	draw_minimap(cub3d);
	mlx_put_image_to_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr,
		cub3d->mlx.mlx_img.ptr, 0, 0);
	interact_door(cub3d, cub3d->player.pos);
	move_monsters(cub3d);
	shoot_monsters(cub3d);
	sound_close_monster(cub3d);
	update_time_n_draw_fps(cub3d);
	reload(cub3d);
	print_hud(cub3d);
	return (0);
}
