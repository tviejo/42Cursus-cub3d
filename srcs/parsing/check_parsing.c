/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:57:50 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/14 18:30:31 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_unwanted_item(t_cub3d *cub3d, int x, int y)
{
	const int	item = cub3d->map.m[y][x];

	return (item == '0' || item == 'N' || item == 'S' || item == 'E'
		|| item == 'W' || item == 'C' || item == 'O' || item == 'A');
}

static int	check_pos(t_cub3d *cub3d, int x, int y)
{
	if (y > 0 && is_unwanted_item(cub3d, x, y - 1))
	{
		ft_dprintf(2, "error: map invalid at %d,%d\n", x, y - 1);
		return (EXIT_FAILURE);
	}
	if (x > 0 && is_unwanted_item(cub3d, x - 1, y))
	{
		ft_dprintf(2, "error: map invalid at %d,%d\n", x - 1, y);
		return (EXIT_FAILURE);
	}
	if (cub3d->map.m[y + 1] && is_unwanted_item(cub3d, x, y + 1))
	{
		ft_dprintf(2, "error: map invalid at %d,%d\n", x, y + 1);
		return (EXIT_FAILURE);
	}
	if (cub3d->map.m[y][x + 1] && is_unwanted_item(cub3d, x + 1, y))
	{
		ft_dprintf(2, "error: map invalid at %d,%d\n", x + 1, y);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_door(t_cub3d *cub3d, int x, int y)
{
	if (cub3d->map.m[y - 1][x] == '1' && cub3d->map.m[y + 1][x] == '1')
		return (EXIT_SUCCESS);
	else if (cub3d->map.m[y][x - 1] == '1' && cub3d->map.m[y][x + 1] == '1')
		return (EXIT_SUCCESS);
	else
	{
		ft_dprintf(2, "invalid door at %d,%d\n", x, y);
		return (EXIT_FAILURE);
	}
}

int	check_parsing_map(t_cub3d *cub3d)
{
	int	y;
	int	x;

	y = 0;
	while (y < cub3d->map.height + 2)
	{
		x = 0;
		while (cub3d->map.m[y][x])
		{
			if (cub3d->map.m[y][x] == '9')
				if (check_pos(cub3d, x, y) == EXIT_FAILURE)
					return (EXIT_FAILURE);
			if (cub3d->map.m[y][x] == 'C' || cub3d->map.m[y][x] == 'C')
				if (check_door(cub3d, x, y) == EXIT_FAILURE)
					return (EXIT_FAILURE);
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int	check_parsing(t_cub3d *cub3d)
{
	if (cub3d->map.height == 0 || cub3d->map.width == 0 || cub3d->map.m == NULL)
		return (ft_dprintf(2, "error: missing map\n"), EXIT_FAILURE);
	if (cub3d->map.north_tfname == NULL || cub3d->map.south_tfname == NULL
		|| cub3d->map.west_tfname == NULL || cub3d->map.east_tfname == NULL)
		return (ft_dprintf(2, "error: missing texture\n"), EXIT_FAILURE);
	if (cub3d->map.col_floor.r == -1 || cub3d->map.col_floor.g == -1
		|| cub3d->map.col_floor.b == -1)
		return (ft_dprintf(2, "error: bad floor color\n"), EXIT_FAILURE);
	if (cub3d->map.col_ceil.r == -1 || cub3d->map.col_ceil.g == -1
		|| cub3d->map.col_ceil.b == -1)
		return (ft_dprintf(2, "error: bad ceiling color\n"), EXIT_FAILURE);
	if (cub3d->map.m == NULL)
		return (ft_dprintf(2, "error: missing map\n"), EXIT_FAILURE);
	if (cub3d->player.pos.x == -1 || cub3d->player.pos.y == -1)
		return (ft_dprintf(2, "error: missing player\n"), EXIT_FAILURE);
	if (check_parsing_map(cub3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
