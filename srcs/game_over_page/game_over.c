/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:49:29 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/07 15:57:53 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_game_over_page(t_cub3d *cub3d)
{
	if (MOUSE == 1)
		mlx_mouse_show(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr);
	mlx_clear_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr);
	mlx_string_put(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, 950, 500, 0xFF0000,
		"Game Over: y to exit, n to start again");
	return (0);
}
