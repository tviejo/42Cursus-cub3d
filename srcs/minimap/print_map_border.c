/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_border.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:40:29 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/05 18:43:07 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	plot_circle_points(t_cub3d *cub, t_point pos_c, t_point pos,
		int color)
{
	int			i;
	const int	x = pos.x;
	const int	y = pos.y;
	const int	xc = pos_c.x;
	const int	yc = pos_c.y;

	i = 0;
	while (i < 8)
	{
		img_put_pix32_safe(&cub->mlx.mlx_img, xc + x + i, yc + y + i, color);
		img_put_pix32_safe(&cub->mlx.mlx_img, xc - x - i, yc + y + i, color);
		img_put_pix32_safe(&cub->mlx.mlx_img, xc + x + i, yc - y - i, color);
		img_put_pix32_safe(&cub->mlx.mlx_img, xc - x - i, yc - y - i, color);
		img_put_pix32_safe(&cub->mlx.mlx_img, xc + y + i, yc + x + i, color);
		img_put_pix32_safe(&cub->mlx.mlx_img, xc - y - i, yc + x + i, color);
		img_put_pix32_safe(&cub->mlx.mlx_img, xc + y + i, yc - x - i, color);
		img_put_pix32_safe(&cub->mlx.mlx_img, xc - y - i, yc - x - i, color);
		i++;
	}
}

void	print_map_border(t_cub3d *cub, t_point pos_c, int r, int color)
{
	int	x;
	int	y;
	int	d;

	x = 0;
	y = r;
	d = 3 - 2 * r;
	while (y >= x)
	{
		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
		{
			d = d + 4 * x + 6;
		}
		plot_circle_points(cub, pos_c, (t_point){{x}, {y}}, color);
	}
}
