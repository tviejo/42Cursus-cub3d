/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:07:14 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/28 17:44:36 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	print_player(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = -3;
	while (x < 3)
	{
		y = -3;
		while (y < 3)
		{
			img_pix_put(cub3d, cub3d->player.y * 10 + x,
				cub3d->player.x * 10 + y, COL_RED);
			y++;
		}
		x++;
	}
}

static int	print_square(size_t i, size_t j, t_cub3d *cub3d, int color)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			img_pix_put(cub3d, j * 10 + x, i * 10 + y, color);
			y++;
		}
		x++;
	}
	return (EXIT_SUCCESS);
}

int	draw_minimap(t_cub3d *cub3d)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < cub3d->map.height + 1)
	{
		j = 0;
		while (j < cub3d->map.width)
		{
			if (cub3d->map.m[i][j] == '1')
				print_square(i, j, cub3d, COL_BLUE);
			else if (cub3d->map.m[i][j] == '0')
				print_square(i, j, cub3d, COL_WHITE);
			else if (cub3d->map.m[i][j] == 'C')
				print_square(i, j, cub3d, COL_MAGENTA);
			else if (cub3d->map.m[i][j] == 'O')
				print_square(i, j, cub3d, COL_GREEN);
			j++;
		}
		i++;
	}
	print_player(cub3d);
	return (EXIT_SUCCESS);
}
