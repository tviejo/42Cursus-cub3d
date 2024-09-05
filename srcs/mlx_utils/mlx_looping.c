/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_looping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:57:20 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/05 14:17:55 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mlx_looping(t_cub3d *cub3d)
{
	cub3d->game.page = LANDING_PAGE;
	mlx_loop_hook(cub3d->mlx.mlx_ptr, &render, cub3d);
	mlx_hook(cub3d->mlx.win_ptr, 17, StructureNotifyMask, &ft_close_cr, cub3d);
	mlx_hook(cub3d->mlx.win_ptr, KeyPress, KeyPressMask, &key_press, cub3d);
	mlx_hook(cub3d->mlx.win_ptr, KeyRelease, KeyReleaseMask, &key_release,
		cub3d);
	mlx_loop(cub3d->mlx.mlx_ptr);
	return (EXIT_SUCCESS);
}
