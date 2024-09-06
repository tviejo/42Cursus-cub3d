/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:31:38 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/06 13:44:44 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_triangle	find_coordinate(t_cub3d *cub)
{
	const t_pt2d	p0 = (t_pt2d){.x = 150, .y = 150, .color = COL_RED};
	t_pt2d			p1;
	t_pt2d			p2;
	t_pt2d			p3;
	t_triangle		triangle;

	p1 = (t_pt2d){.x = p0.x + cub->game.minimap_size * cos(cub->player.dir),
		.y = p0.y - cub->game.minimap_size * sin(cub->player.dir),
		.color = COL_RED};
	p2 = (t_pt2d){.x = p0.x + cub->game.minimap_size / 3 * cos(cub->player.dir
			+ M_PI_2), .y = p0.y - cub->game.minimap_size / 3
		* sin(cub->player.dir + M_PI_2), .color = COL_RED};
	p3 = (t_pt2d){.x = p0.x + cub->game.minimap_size / 3 * cos(cub->player.dir
			+ 3 * M_PI_2), .y = p0.y - cub->game.minimap_size / 3
		* sin(cub->player.dir + 3 * M_PI_2), .color = COL_RED};
	triangle.p0 = p1;
	triangle.p1 = p2;
	triangle.p2 = p3;
	triangle.color = p0.color;
	return (triangle);
}

static t_pt2d	calculate_point(t_triangle triangle, int i)
{
	double	x;
	double	y;
	double	dist;

	x = triangle.p2.x - triangle.p1.x;
	y = triangle.p2.y - triangle.p1.y;
	dist = i / sqrt(x * x + y * y);
	x *= dist;
	y *= dist;
	return ((t_pt2d){.x = triangle.p1.x + x, .y = triangle.p1.y + y,
		.color = COL_RED});
}

static void	print_triangle(t_cub3d *cub, t_triangle triangle)
{
	const double	x = triangle.p2.x - triangle.p1.x;
	const double	y = triangle.p2.y - triangle.p1.y;
	const double	dist = sqrt(x * x + y * y);
	int				i;
	t_pt2d			new_point;

	i = 0;
	draw_line(&cub->mlx.mlx_img, triangle.p0, triangle.p1);
	draw_line(&cub->mlx.mlx_img, triangle.p0, triangle.p2);
	draw_line(&cub->mlx.mlx_img, triangle.p2, triangle.p1);
	while (i < dist)
	{
		new_point = calculate_point(triangle, i);
		draw_line(&cub->mlx.mlx_img, new_point, triangle.p0);
		i++;
	}
}

void	print_player(t_cub3d *cub)
{
	t_triangle	triangle;

	triangle = find_coordinate(cub);
	print_triangle(cub, triangle);
}
