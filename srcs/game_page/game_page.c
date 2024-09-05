/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:22:41 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/05 13:43:02 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	mouse(t_cub3d *cub3d)
{
	static int x = WINDOW_WIDTH / 2;
	int	x1;
	int	y1;

	if (x < 100 || x > WINDOW_WIDTH - 100)
	{
		x = WINDOW_WIDTH / 2;
		mlx_mouse_move(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, x, WINDOW_HEIGHT / 2);
	}
	mlx_mouse_get_pos(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, &x1, &y1);
	rotate_player(&cub3d->player, (x1 - cub3d->inputs.mouse_x) * 0.001);
	cub3d->inputs.mouse_x = x1;
	cub3d->inputs.mouse_y = y1;
}

int	render_game_page(t_cub3d *cub3d)
{
	mouse(cub3d);
	update_player_pos(cub3d);
	render_frame(cub3d);
	draw_minimap(cub3d);
	mlx_put_image_to_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr,
		cub3d->mlx.mlx_img.ptr, 0, 0);
	interact_door(cub3d, cub3d->player.pos);
	update_n_draw_fps(cub3d);
	return (0);
}
