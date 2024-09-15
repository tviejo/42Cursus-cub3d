/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_looping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:57:20 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/15 12:01:49 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	on_win_change(t_cub3d *cub)
{
	amlx_update_img_size(cub);
	return (0);
}

int	mlx_set_hooks_n_loop(t_cub3d *cub)
{
	void *const	wp = cub->mlx.win_ptr;

	mlx_loop_hook(cub->mlx.mlx_ptr, &render, cub);
	mlx_hook(wp, DestroyNotify, StructureNotifyMask, &on_win_close, cub);
	mlx_hook(wp, ConfigureNotify, StructureNotifyMask, &on_win_change, cub);
	mlx_hook(wp, KeyPress, KeyPressMask, &on_key_press, cub);
	mlx_hook(wp, KeyRelease, KeyReleaseMask, &on_key_release, cub);
	mlx_mouse_hook(wp, &on_mouse_btn_press, cub);
	mlx_hook(wp, ButtonRelease, ButtonReleaseMask, &on_mouse_btn_release, cub);
	mlx_loop(cub->mlx.mlx_ptr);
	return (EXIT_SUCCESS);
}
