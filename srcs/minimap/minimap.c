/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:07:14 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/30 14:03:09 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_player(t_cub3d *cub)
{
	const t_pt2d	p0 = (t_pt2d){.x = 10 * cub->player.x,
		.y = 10 * cub->player.y, .color = COL_RED};
	t_pt2d			p1;
	int				x;
	int				y;

	x = -3;
	while (x < 3)
	{
		y = -3;
		while (y < 3)
		{
			img_put_pix32_safe(&cub->mlx.mlx_img, p0.x + x, p0.y + y, COL_RED);
			y++;
		}
		x++;
	}
	p1 = (t_pt2d){.x = p0.x + 16 * cos(cub->player.dir - M_PI_2),
		.y = p0.y + 16 * sin(cub->player.dir - M_PI_2)};
	draw_line(&cub->mlx.mlx_img, p0, p1);
}

static int	print_square(t_image *img, t_point pos, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			img_put_pix32_safe(img, pos.x * 10 + x, pos.y * 10 + y, color);
			y++;
		}
		x++;
	}
	return (EXIT_SUCCESS);
}

int	draw_minimap(t_cub3d *cub)
{
	t_image *const	img = &cub->mlx.mlx_img;
	t_point			pos;
	int				item;

	pos.y = 0;
	while (pos.y < cub->map.height + 1)
	{
		pos.x = 0;
		while (pos.x < cub->map.width)
		{
			item = cub->map.m[pos.y][pos.x];
			if (item == '1')
				print_square(img, pos, COL_BLUE);
			else if (item == '0')
				print_square(img, pos, COL_WHITE);
			else if (item == 'C')
				print_square(img, pos, COL_MAGENTA);
			else if (item == 'O')
				print_square(img, pos, COL_GREEN);
			pos.x++;
		}
		pos.y++;
	}
	print_player(cub);
	return (EXIT_SUCCESS);
}
