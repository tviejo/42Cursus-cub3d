/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   landing_page.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:21:37 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/08 21:58:23 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_landing_page(t_cub3d *cub3d)
{
	char	*dificulty;

	mlx_clear_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr);
	if (MOUSE == 1)
		mlx_mouse_show(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr);
	mlx_string_put(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, 1000, 500, 0xFFFFFF,
		"Press Space to start");
	mlx_string_put(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, 1000, 550, 0xFFFFFF,
		"Choose difficulty: ");
	dificulty = ft_itoa(cub3d->game.dificulty);
	mlx_string_put(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, 1120, 550, 0xFFFFFF,
		dificulty);
	free(dificulty);
	return (0);
}
