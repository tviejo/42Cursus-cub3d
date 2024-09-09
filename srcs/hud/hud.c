/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:27:53 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/09 19:41:46 by tviejo           ###   ########.fr       */
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

static void	print_gun(t_cub3d *cub)
{
	t_image	*gun;
	int		x;
	int		y;
	int		r_x;
	int		r_y;

	gun = &cub->mlx.gun;
	x = 3 * WINDOW_WIDTH / 5 - gun->dim.width;
	while (x < 3 * WINDOW_WIDTH / 5)
	{
		y = WINDOW_HEIGHT - gun->dim.height ;
		while (y < WINDOW_HEIGHT)
		{
			r_x = x - (3 * WINDOW_WIDTH / 5 - gun->dim.width);
			r_y = y - (WINDOW_HEIGHT - gun->dim.height);
			if (gun->pixels[(r_y * gun->line_size) + (r_x * (gun->bpp / 8))])
				img_pix_put(&cub->mlx.mlx_img, x, y,
					*(int *)(gun->pixels + (r_y * gun->line_size)
						+ (r_x * (gun->bpp / 8))));
			y++;
		}
		x++;
	}
}

void	print_hud(t_cub3d *cub)
{
	print_gun(cub);
	print_cross(cub);
	print_health_bar(cub);
}
