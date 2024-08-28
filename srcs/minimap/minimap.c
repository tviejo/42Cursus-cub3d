/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:07:14 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/29 01:22:07 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	print_player(t_cub3d *cub3d)
{
	const t_pt2d	p0 = (t_pt2d){.x = 10 * cub3d->player.x,
		.y = 10 * cub3d->player.y, .color = COL_RED};
	t_pt2d			p1;
	int				x;
	int				y;

	x = -3;
	while (x < 3)
	{
		y = -3;
		while (y < 3)
		{
			img_pix_put(cub3d, p0.x + x, p0.y + y, COL_RED);
			y++;
		}
		x++;
	}
	p1 = (t_pt2d){.x = p0.x + 16 * cos(cub3d->player.dir - M_PI_2),
		.y = p0.y + 16 * sin(cub3d->player.dir - M_PI_2)};
	draw_line(&cub3d->mlx, p0, p1);
}

static int	print_square(size_t x, size_t y, t_cub3d *cub3d, int color)
{
	size_t	xadd;
	size_t	yadd;

	xadd = 0;
	while (xadd < 10)
	{
		yadd = 0;
		while (yadd < 10)
		{
			img_pix_put(cub3d, x * 10 + xadd, y * 10 + yadd, color);
			yadd++;
		}
		xadd++;
	}
	return (EXIT_SUCCESS);
}

int	draw_minimap(t_cub3d *cub3d)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < cub3d->map.height + 1)
	{
		x = 0;
		while (x < cub3d->map.width)
		{
			if (cub3d->map.m[y][x] == '1')
				print_square(x, y, cub3d, COL_BLUE);
			else if (cub3d->map.m[y][x] == '0')
				print_square(x, y, cub3d, COL_WHITE);
			else if (cub3d->map.m[y][x] == 'C')
				print_square(x, y, cub3d, COL_MAGENTA);
			else if (cub3d->map.m[y][x] == 'O')
				print_square(x, y, cub3d, COL_GREEN);
			x++;
		}
		y++;
	}
	print_player(cub3d);
	return (EXIT_SUCCESS);
}
