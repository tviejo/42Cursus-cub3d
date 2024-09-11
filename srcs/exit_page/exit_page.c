/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:22:34 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/11 22:37:02 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_exit_page(t_cub3d *cub3d)
{
	mlx_put_image_to_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr,
		cub3d->mlx.text[TXID_EXIT].ptr, 0, 0);
	return (0);
}
//if (MOUSE == 1)
	//	mlx_mouse_show(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr);