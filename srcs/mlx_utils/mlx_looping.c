/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_looping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:57:20 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/13 10:48:28 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mlx_set_hooks_n_loop(t_cub3d *cub3d)
{
	mlx_loop_hook(cub3d->mlx.mlx_ptr, &render, cub3d);
	mlx_hook(cub3d->mlx.win_ptr, 17, StructureNotifyMask, &ft_close_cr, cub3d);
	mlx_hook(cub3d->mlx.win_ptr, KeyPress, KeyPressMask, &key_press, cub3d);
	mlx_hook(cub3d->mlx.win_ptr, KeyRelease, KeyReleaseMask, &key_release,
		cub3d);
	mlx_mouse_hook(cub3d->mlx.win_ptr, &mouse_hook, cub3d);
	mlx_loop(cub3d->mlx.mlx_ptr);
	return (EXIT_SUCCESS);
}
