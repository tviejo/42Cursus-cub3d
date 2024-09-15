/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:52:52 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/15 20:02:06 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* pourquoi mlx_mouse_hide() dans mouse_move() ?

//if (MOUSE == 1)
	//	mlx_mouse_hide(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr);
*/

void	mouse_move(t_cub3d *cub)
{
	static int	x = WINDOW_WIDTH / 2;
	static int	y = WINDOW_HEIGHT / 2;
	int			x1;
	int			y1;

	if (x < 100 || x > cub->mlx.mlx_img.dim.width - 100)
	{
		x = cub->mlx.mlx_img.dim.width / 2;
		y = cub->mlx.mlx_img.dim.height / 2;
		mlx_mouse_move(cub->mlx.mlx_ptr, cub->mlx.win_ptr, x, y);
		cub->inputs.mouse_x = x;
		cub->inputs.mouse_y = y;
	}
	else
	{
		mlx_mouse_get_pos(cub->mlx.mlx_ptr, cub->mlx.win_ptr, &x1, &y1);
		rotate_player(&cub->player, -(x1 - cub->inputs.mouse_x)
			* M_SENSITIVITY);
		cub->inputs.mouse_x = x1;
		cub->inputs.mouse_y = y1;
		x = x1;
		y = y1;
	}
}

int	on_mouse_btn_press(int button, int x, int y, t_cub3d *cub)
{
	(void)x;
	(void)y;
	if (button == 1)
		cub->inputs.ms_fire = true;
	return (EXIT_SUCCESS);
}

int	on_mouse_btn_release(int button, int x, int y, t_cub3d *cub)
{
	(void)x;
	(void)y;
	if (button == 1)
		cub->inputs.ms_fire = false;
	return (EXIT_SUCCESS);
}
