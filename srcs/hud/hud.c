/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:27:53 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/11 00:01:04 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_cross(t_cub3d *cub)
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

inline static void	put_pixel(t_image *img, int x, int y, int color)
{
	*(t_uint *)(img->pixels + y * img->line_size + 4 * x) = color;
}

static void	draw_texture(t_cub3d *cub, t_point pos, t_tex_id texid)
{
	t_image	*tex;
	t_point	dst;
	t_point	src;
	int		pixel;

	tex = &cub->mlx.text[texid];
	dst.x = pos.x - tex->dim.width;
	while (dst.x < pos.x)
	{
		src.x = dst.x - (pos.x - tex->dim.width);
		dst.y = pos.y - tex->dim.height ;
		while (dst.y < pos.y)
		{
			src.y = dst.y - (pos.y - tex->dim.height);
			pixel = *(int *)(tex->pixels + src.y * tex->line_size + src.x * 4);
			if (pixel & 255)
				put_pixel(&cub->mlx.mlx_img, dst.x, dst.y, pixel);
			dst.y++;
		}
		dst.x++;
	}
}

static void	print_remaining_ammo(t_cub3d *cub)
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

void	draw_hud(t_cub3d *cub)
{
	static struct timeval	old_time = {.tv_sec = 0, .tv_usec = 0};
	static int				i = 0;
	const t_point			pos = {	.x = 0.7 * cub->mlx.mlx_img.dim.width
		+ 0.25 * cub->player.walk_height_shift,
		.y = cub->mlx.mlx_img.dim.height + 0.5 * cub->player.walk_height_shift};

	if (cub->inputs.has_fired)
	{
		old_time = cub->game.last_time;
		cub->inputs.has_fired = false;
		i = 0;
	}
	if (old_time.tv_sec == cub->game.last_time.tv_sec && i < 10)
		draw_texture(cub, (t_point){.x = 0.77 * pos.x, .y = 0.8 * pos.y},
			TXID_FIRE);
	if (cub->inputs.reload)
		draw_texture(cub, pos, TXID_GUN_RELOAD);
	else
		draw_texture(cub, pos, TXID_GUN);
	draw_cross(cub);
	draw_health_bar(cub);
	print_remaining_ammo(cub);
	i++;
}
