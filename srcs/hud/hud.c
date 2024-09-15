/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:27:53 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/15 19:53:01 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_cross(t_cub3d *cub)
{
	const int	width = cub->mlx.mlx_img.dim.width;
	const int	height = cub->mlx.mlx_img.dim.height;

	draw_line(&cub->mlx.mlx_img, (t_pt2d){.x = width / 2 - 20,
		.y = height / 2, .color = COL_GREEN}, (t_pt2d){.x = width
		/ 2 - 5, .y = height / 2, .color = COL_GREEN});
	draw_line(&cub->mlx.mlx_img, (t_pt2d){.x = width / 2 + 20,
		.y = height / 2, .color = COL_GREEN}, (t_pt2d){.x = width
		/ 2 + 5, .y = height / 2, .color = COL_GREEN});
	draw_line(&cub->mlx.mlx_img, (t_pt2d){.x = width / 2,
		.y = height / 2 - 20, .color = COL_GREEN},
		(t_pt2d){.x = width / 2, .y = height / 2 - 5,
		.color = COL_GREEN});
	draw_line(&cub->mlx.mlx_img, (t_pt2d){.x = width / 2,
		.y = height / 2 + 20, .color = COL_GREEN},
		(t_pt2d){.x = width / 2, .y = height / 2 + 5,
		.color = COL_GREEN});
}

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
	const int	height = cub->mlx.mlx_img.dim.height;
	char		*info;

	mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, 50, height - 150,
		COL_WHITE, "Ammo:");
	info = ft_itoa(cub->player.ammo);
	if (cub->player.ammo <= 5)
	{
		mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, 100, height
			- 150, COL_RED, info);
		if (cub->player.ammo == 0)
			mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, 50, height
				- 120, COL_WHITE, "press R to reload");
	}
	else
		mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, 100, height
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
