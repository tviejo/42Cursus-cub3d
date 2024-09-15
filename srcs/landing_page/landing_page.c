/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   landing_page.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:21:37 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/14 19:30:44 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// if (MOUSE == 1)
//	mlx_mouse_show(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr);

int	render_landing_page(t_cub3d *cub3d)
{
	char	*difficulty;

	mlx_put_image_to_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr,
		cub3d->mlx.text[TXID_LANDING].ptr, 0, 0);
	mlx_string_put(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, WINDOW_WIDTH - 350,
		WINDOW_HEIGHT - 60, 0xFFFFFF, "Choose difficulty: ");
	difficulty = ft_itoa(cub3d->game.difficulty);
	mlx_string_put(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, WINDOW_WIDTH - 165,
		WINDOW_HEIGHT - 60, 0xFFFFFF, difficulty);
	free(difficulty);
	return (0);
}
