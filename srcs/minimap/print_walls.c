/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:31:28 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/07 16:14:39 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_inside_circle(int x, int y, t_cub3d *cub)
{
	const int	x_s = (x - (cub->player.pos.x * cub->game.minimap_size)) * (x
			- (cub->player.pos.x * cub->game.minimap_size));
	const int	y_s = (y - (cub->player.pos.y * cub->game.minimap_size)) * (y
			- (cub->player.pos.y * cub->game.minimap_size));

	if (x_s + y_s < 10000)
		return (true);
	else
		return (false);
}

static int	print_square(t_image *img, t_point pos, int color, t_cub3d *cub)
{
	int	x;
	int	y;

	x = 0;
	while (x < cub->game.minimap_size)
	{
		y = 0;
		while (y < cub->game.minimap_size)
		{
			if (is_inside_circle(pos.x * cub->game.minimap_size + x, pos.y
					* cub->game.minimap_size + y, cub) == true)
				img_put_pix32_safe(img, 150 + pos.x * cub->game.minimap_size + x
					- (cub->player.pos.x * cub->game.minimap_size), 150 + pos.y
					* cub->game.minimap_size + y - (cub->player.pos.y
						* cub->game.minimap_size), color);
			y++;
		}
		x++;
	}
	return (EXIT_SUCCESS);
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
