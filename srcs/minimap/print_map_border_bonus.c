/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_border.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:40:29 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/07 19:42:52 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline static void	put_pixel(t_image *img, int x, int y, int color)
{
	*(t_uint *)(img->pixels + y * img->line_size + 4 * x) = color;
}

static void	plot_circle_points(t_cub3d *cub, t_point pos, int color)
{
	int				i;
	t_image *const	img = &cub->mlx.mlx_img;
	const int		xc = cub->game.minimap_center.x;
	const int		yc = cub->game.minimap_center.y;

	i = 0;
	while (i < 8)
	{
		put_pixel(img, xc + pos.x + i, yc + pos.y + i, color);
		put_pixel(img, xc - pos.x - i, yc + pos.y + i, color);
		put_pixel(img, xc + pos.x + i, yc - pos.y - i, color);
		put_pixel(img, xc - pos.x - i, yc - pos.y - i, color);
		put_pixel(img, xc + pos.y + i, yc + pos.x + i, color);
		put_pixel(img, xc - pos.y - i, yc + pos.x + i, color);
		put_pixel(img, xc + pos.y + i, yc - pos.x - i, color);
		put_pixel(img, xc - pos.y - i, yc - pos.x - i, color);
		i++;
	}
}

void	print_map_border(t_cub3d *cub, int r, int color)
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
		plot_circle_points(cub, (t_point){{x}, {y}}, color);
	}
}
