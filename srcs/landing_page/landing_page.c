/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   landing_page.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:21:37 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/10 04:39:35 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//if (MOUSE == 1)
	//	mlx_mouse_show(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr);

int	render_landing_page(t_cub3d *cub3d)
{
	char	*dificulty;

	mlx_clear_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr);
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
