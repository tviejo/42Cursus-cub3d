/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:27:53 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/09 18:15:03 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_cross(t_cub3d *cub)
{
	draw_line(&cub->mlx.mlx_img, (t_pt2d){.x = WINDOW_WIDTH / 2 - 20,
		.y = WINDOW_HEIGHT / 2, .color = COL_GREEN}, (t_pt2d){.x = WINDOW_WIDTH
		/ 2 - 5, .y = WINDOW_HEIGHT / 2, .color = COL_GREEN});
	draw_line(&cub->mlx.mlx_img, (t_pt2d){.x = WINDOW_WIDTH / 2 + 20,
		.y = WINDOW_HEIGHT / 2, .color = COL_GREEN}, (t_pt2d){.x = WINDOW_WIDTH
		/ 2 + 5, .y = WINDOW_HEIGHT / 2, .color = COL_GREEN});
	draw_line(&cub->mlx.mlx_img, (t_pt2d){.x = WINDOW_WIDTH / 2,
		.y = WINDOW_HEIGHT / 2 - 20, .color = COL_GREEN},
		(t_pt2d){.x = WINDOW_WIDTH / 2, .y = WINDOW_HEIGHT / 2 - 5,
		.color = COL_GREEN});
	draw_line(&cub->mlx.mlx_img, (t_pt2d){.x = WINDOW_WIDTH / 2,
		.y = WINDOW_HEIGHT / 2 + 20, .color = COL_GREEN},
		(t_pt2d){.x = WINDOW_WIDTH / 2, .y = WINDOW_HEIGHT / 2 + 5,
		.color = COL_GREEN});
}

void	print_hud(t_cub3d *cub)
{
	print_cross(cub);
	print_health_bar(cub);
}
