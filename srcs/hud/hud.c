/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:27:53 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/10 12:23:12 by tviejo           ###   ########.fr       */
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

static void	print_texture(t_cub3d *cub, t_pointd pos, t_texture texture)
{
	t_image	*gun;
	int		x;
	int		y;
	int		r_x;
	int		r_y;

	gun = &cub->mlx.text[texture];
	x = pos.x - gun->dim.width;
	while (x < pos.x)
	{
		y = pos.y - gun->dim.height ;
		while (y < pos.y)
		{
			r_x = x - (pos.x - gun->dim.width);
			r_y = y - (pos.y - gun->dim.height);
			if (gun->pixels[(r_y * gun->line_size) + (r_x * (gun->bpp / 8))])
				img_pix_put(&cub->mlx.mlx_img, x, y,
					*(int *)(gun->pixels + (r_y * gun->line_size)
						+ (r_x * (gun->bpp / 8))));
			y++;
		}
		x++;
	}
}

static void print_remaining_ammo(t_cub3d *cub)
{
	char	*info;

	mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, 50,
		WINDOW_HEIGHT - 150, COL_WHITE, "Ammo:");
	info = ft_itoa(cub->player.ammo);
	if (cub->player.ammo <= 5)
	{
		mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, 100,
			WINDOW_HEIGHT - 150, COL_RED, info);
		if (cub->player.ammo == 0)
			mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, 50,
				WINDOW_HEIGHT - 120, COL_WHITE, "press R to reload");
	}
	else
		mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, 100,
			WINDOW_HEIGHT - 150, COL_WHITE, info);
	free(info);
}

void	print_hud(t_cub3d *cub)
{
	static struct timeval	old_time = {.tv_sec = 0, .tv_usec = 0};
	static int				i = 0;

	if (cub->inputs.has_fired)
	{
		old_time = cub->game.last_time;
		cub->inputs.has_fired = false;
		i = 0;
	}
	if (old_time.tv_sec == cub->game.last_time.tv_sec && i < 10)
		print_texture(cub, (t_pointd){.x = WINDOW_WIDTH * 0.54, .y = WINDOW_HEIGHT * 0.8}, FIRE);
	if (cub->inputs.reload)
		print_texture(cub, (t_pointd){.x = WINDOW_WIDTH * 0.7, .y = WINDOW_HEIGHT}, RELOAD);
	else
		print_texture(cub, (t_pointd){.x = WINDOW_WIDTH * 0.7, .y = WINDOW_HEIGHT}, GUN);
	print_cross(cub);
	print_health_bar(cub);
	print_remaining_ammo(cub);
	i++;
}
