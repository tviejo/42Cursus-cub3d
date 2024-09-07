/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:27:57 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/07 16:13:12 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_health_bar(t_cub3d *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->player.health * 5)
	{
		j = 0;
		while (j < 10)
		{
			if (cub->player.health > 75)
				img_put_pix32_safe(&cub->mlx.mlx_img, WINDOW_WIDTH / 2 - 250
					+ i, WINDOW_HEIGHT - 150 + j, COL_GREEN);
			else if (cub->player.health > 50)
				img_put_pix32_safe(&cub->mlx.mlx_img, WINDOW_WIDTH / 2 - 250
					+ i, WINDOW_HEIGHT - 150 + j, COL_YELLOW);
			else if (cub->player.health > 25)
				img_put_pix32_safe(&cub->mlx.mlx_img, WINDOW_WIDTH / 2 - 250
					+ i, WINDOW_HEIGHT - 150 + j, COL_ORANGE);
			else
				img_put_pix32_safe(&cub->mlx.mlx_img, WINDOW_WIDTH / 2 - 250
					+ i, WINDOW_HEIGHT - 150 + j, COL_RED);
			j++;
		}
		i++;
	}
}
