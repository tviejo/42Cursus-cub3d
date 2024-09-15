/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:27:53 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/14 19:33:23 by tviejo           ###   ########.fr       */
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

/*inline static void	put_pixel(t_image *img, int x, int y, int color)
{
	*(t_uint *)(img->pixels + y * img->line_size + 4 * x) = color;
}*/

/* 'posBR' is the position on screen (mlx_img) of the bottom right pixel
 * of the texture
*/
/*static void	draw_hud_texture(t_cub3d *cub, t_point posBR, t_tex_id texid)
{
	t_image	*tex;
	t_point	dst;
	t_point	src;
	int		pixel;

	tex = &cub->mlx.text[texid];
	src.y = 0;
	dst.y = posBR.y - tex->dim.height;
	while (dst.y < posBR.y)
	{
		src.x = 0;
		dst.x = posBR.x - tex->dim.width ;
		while (dst.x < posBR.x)
		{
			pixel = *(int *)(tex->pixels + src.y * tex->line_size + src.x * 4);
			if (pixel & 255)
				put_pixel(&cub->mlx.mlx_img, dst.x, dst.y, pixel);
			src.x++;
			dst.x++;
		}
		src.y++;
		dst.y++;
	}
}*/

/* 'posBR' is the position on screen (mlx_img) of the bottom right pixel
 * of the texture
*/
static void	draw_hud_texture(t_cub3d *cub, t_point posBR, t_tex_id texid)
{
	copy_image(&cub->mlx.text[texid], cub->mlx.text[texid].dim,
		&cub->mlx.mlx_img, posBR);
}

static void	print_remaining_ammo(t_cub3d *cub)
{
	char	*info;

	mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, 50, WINDOW_HEIGHT - 150,
		COL_WHITE, "Ammo:");
	info = ft_itoa(cub->player.ammo);
	if (cub->player.ammo <= 5)
	{
		mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, 100, WINDOW_HEIGHT
			- 150, COL_RED, info);
		if (cub->player.ammo == 0)
			mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, 50, WINDOW_HEIGHT
				- 120, COL_WHITE, "press R to reload");
	}
	else
		mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, 100, WINDOW_HEIGHT
			- 150, COL_WHITE, info);
	free(info);
}

void	draw_hud(t_cub3d *cub)
{
	static struct timeval	old_time = {.tv_sec = 0, .tv_usec = 0};
	static int				i = 0;
	const t_point			pos = {.x = 0.7 * cub->mlx.mlx_img.dim.width
		+ 0.25 * cub->player.walk_height_shift,
		.y = cub->mlx.mlx_img.dim.height + 0.45 * cub->player.walk_height_shift
		+ 15};

	if (cub->inputs.has_fired)
	{
		old_time = cub->game.last_tod;
		cub->inputs.has_fired = false;
		i = 0;
	}
	if (old_time.tv_sec == cub->game.last_tod.tv_sec && i < 10)
		draw_hud_texture(cub, (t_point){.x = 0.77 * pos.x, .y = 0.8 * pos.y},
			TXID_FIRE);
	if (cub->inputs.reload)
		draw_hud_texture(cub, pos, TXID_GUN_RELOAD);
	else
		draw_hud_texture(cub, pos, TXID_GUN);
	draw_cross(cub);
	draw_health_bar(cub);
	print_remaining_ammo(cub);
	i++;
}
