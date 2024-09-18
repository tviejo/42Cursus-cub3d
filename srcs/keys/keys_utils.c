/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:24:17 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/18 14:02:04 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_keys(t_cub3d *cub)
{
	const int	width = cub->mlx.mlx_img.dim.width;
	const int	height = cub->mlx.mlx_img.dim.height;

	ft_memset(&cub->inputs, 0, sizeof(t_player_inputs));
	cub->inputs.strafe_mode = false;
	mlx_mouse_move(cub->mlx.mlx_ptr, cub->mlx.win_ptr,
		width / 2, height / 2);
	cub->inputs.mouse_x = width / 2;
	cub->inputs.mouse_y = height / 2;
	return (0);
}
