/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:52:52 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/10 12:50:08 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* pourquoi mlx_mouse_hide() dans mouse_move() ?

//if (MOUSE == 1)
	//	mlx_mouse_hide(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr);
*/

void	mouse_move(t_cub3d *cub3d)
{
	static int	x = WINDOW_WIDTH / 2;
	static int	y = WINDOW_HEIGHT / 2;
	int			x1;
	int			y1;

	if (x < 100 || x > WINDOW_WIDTH - 100)
	{
		x = WINDOW_WIDTH / 2;
		y = WINDOW_HEIGHT / 2;
		mlx_mouse_move(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, x, y);
		cub3d->inputs.mouse_x = x;
		cub3d->inputs.mouse_y = y;
	}
	else
	{
		mlx_mouse_get_pos(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, &x1, &y1);
		rotate_player(&cub3d->player, -(x1 - cub3d->inputs.mouse_x)
			* M_SENSITIVITY);
		cub3d->inputs.mouse_x = x1;
		cub3d->inputs.mouse_y = y1;
		x = x1;
		y = y1;
	}
}

int	mouse_hook(int button, int x, int y, t_cub3d *cub3d)
{
	(void)x;
	(void)y;
	if (button == 1 && cub3d->game.page == GAME_PAGE)
	{
		if (cub3d->player.ammo > 0 && cub3d->inputs.reload == false)
		{
			cub3d->inputs.shoot = true;
			cub3d->inputs.has_fired = true;
			cub3d->player.ammo--;
			play_sound(SHOOT, cub3d);
		}
		else
			play_sound(EMPTY, cub3d);
	}
	return (EXIT_SUCCESS);
}
