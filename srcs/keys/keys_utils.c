/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:24:17 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/07 19:01:55 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_keys(t_cub3d *cub3d)
{
	ft_memset(&cub3d->inputs, 0, sizeof(t_player_inputs));
	cub3d->inputs.strafe_mode = true;
	mlx_mouse_move(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr,
		WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	cub3d->inputs.mouse_x = WINDOW_WIDTH / 2;
	cub3d->inputs.mouse_y = WINDOW_HEIGHT / 2;
	return (0);
}
