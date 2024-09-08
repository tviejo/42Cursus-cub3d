/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:27:57 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/08 17:19:08 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*void	print_health_bar(t_cub3d *cub)
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
}*/

void	print_health_bar(t_cub3d *cub)
{
	static const int	colors[] = {COL_RED, COL_ORANGE, COL_YELLOW, COL_GREEN,
		COL_GREEN};
	const t_size2i		dim = {.width = 5 * cub->player.health, .height = 10};
	const t_point		p0 = {.x = (cub->mlx.mlx_img.dim.width >> 1) - 250,
		.y = cub->mlx.mlx_img.dim.height - 80};

	fill_rectangle(&cub->mlx.mlx_img,
		(t_rect){.x0 = p0.x, .y0 = p0.y,
		.x1 = p0.x + dim.width, .y1 = p0.y + dim.height},
		colors[cub->player.health / 25]);
}
