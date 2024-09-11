/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:27:57 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/11 00:03:14 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_health_bar(t_cub3d *cub)
{
	static const int	colors[] = {COL_RED, COL_ORANGE, COL_YELLOW, COL_GREEN,
		COL_GREEN};
	const t_size2i		dim = {.width = 5 * cub->player.health, .height = 10};
	const t_point		p0 = {.x = (cub->mlx.mlx_img.dim.width >> 1) - 250,
		.y = 80};

	fill_rectangle(&cub->mlx.mlx_img,
		(t_rect){.x0 = p0.x, .y0 = p0.y,
		.x1 = p0.x + dim.width, .y1 = p0.y + dim.height},
		colors[cub->player.health / 25]);
}
