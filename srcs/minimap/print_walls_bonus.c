/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:31:28 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/15 12:37:28 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline static void	put_pixel(t_image *img, int x, int y, int color)
{
	*(t_uint *)(img->pixels + y * img->line_size + 4 * x) = color;
}

inline static bool	is_inside_circle(int x, int y, int square_radius)
{
	return (x * x + y * y < square_radius);
}

/*
	t_rect	rc;

	rc.p0 = p0c;
	rc.p1.x = p0c.x + cub->game.minimap_size - 1;
	rc.p1.y = p0c.y + cub->game.minimap_size - 1;
	fill_rectangle(img, rc, color);
*/

static void	print_square(t_image *img, t_point pos, int color, t_cub3d *cub)
{
	const int	radius2 = cub->game.minimap_radius * cub->game.minimap_radius;
	int			x;
	int			y;
	t_point		p0;
	t_point		p0c;

	p0.x = pos.x * cub->game.minimap_size
		- (cub->player.pos.x * cub->game.minimap_size);
	p0.y = pos.y * cub->game.minimap_size
		- (cub->player.pos.y * cub->game.minimap_size);
	p0c.x = p0.x + cub->game.minimap_center.x;
	p0c.y = p0.y + cub->game.minimap_center.y;
	x = 0;
	while (x < cub->game.minimap_size)
	{
		y = 0;
		while (y < cub->game.minimap_size)
		{
			if (is_inside_circle(p0.x + x, p0.y + y, radius2))
				put_pixel(img, p0c.x + x, p0c.y + y, color);
			y++;
		}
		x++;
	}
}

void	print_wall(t_cub3d *cub, t_point pos)
{
	char	item;

	item = cub->map.m[pos.y][pos.x];
	if (item == '1')
		print_square(&cub->mlx.mlx_img, pos, COL_BLUE, cub);
	else if (item == '0')
		print_square(&cub->mlx.mlx_img, pos, COL_WHITE, cub);
	else if (item == 'C')
		print_square(&cub->mlx.mlx_img, pos, COL_MAGENTA, cub);
	else if (item == 'O')
		print_square(&cub->mlx.mlx_img, pos, COL_GREEN, cub);
	pos.x++;
}
