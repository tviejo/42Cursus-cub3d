/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:57:50 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/28 17:19:54 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	value(t_cub3d *cub3d, size_t i, size_t j)
{
	if (cub3d->map.m[i][j] == '0')
		return (true);
	if (cub3d->map.m[i][j] == 'N')
		return (true);
	if (cub3d->map.m[i][j] == 'S')
		return (true);
	if (cub3d->map.m[i][j] == 'E')
		return (true);
	if (cub3d->map.m[i][j] == 'W')
		return (true);
	return (false);
}

static bool	check(t_cub3d *cub3d, size_t i, size_t j)
{
	if (i > 0 && value(cub3d, i - 1, j) == true)
	{
		ft_dprintf(2, "error: map invalid at %d,%d\n", i - 1, j);
		return (EXIT_FAILURE);
	}
	if (j > 0 && value(cub3d, i, j - 1) == true)
	{
		ft_dprintf(2, "error: map invalid at %d,%d\n", i, j - 1);
		return (EXIT_FAILURE);
	}
	if (cub3d->map.m[i + 1] && value(cub3d, i + 1, j) == true)
	{
		ft_dprintf(2, "error: map invalid at %d,%d\n", i + 1, j);
		return (EXIT_FAILURE);
	}
	if (cub3d->map.m[i][j + 1] && value(cub3d, i, j + 1) == true)
	{
		ft_dprintf(2, "error: map invalid at %d,%d\n", i, j + 1);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_parsing_map(t_cub3d *cub3d)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < cub3d->map.height + 2)
	{
		j = 0;
		while (cub3d->map.m[i][j])
		{
			if (cub3d->map.m[i][j] == '9')
				if (check(cub3d, i, j) == EXIT_FAILURE)
					return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_parsing(t_cub3d *cub3d)
{
	if (cub3d->map.height == 0 || cub3d->map.width == 0)
		return (ft_dprintf(2, "error: missing map\n"), EXIT_FAILURE);
	if (cub3d->map.no == NULL || cub3d->map.so == NULL || cub3d->map.we == NULL
		|| cub3d->map.ea == NULL)
		return (ft_dprintf(2, "error: missing texture\n"), EXIT_FAILURE);
	if (cub3d->map.col_floor.r == -1 || cub3d->map.col_floor.g == -1
		|| cub3d->map.col_floor.b == -1)
		return (ft_dprintf(2, "error: bad floor color\n"), EXIT_FAILURE);
	if (cub3d->map.col_ceil.r == -1 || cub3d->map.col_ceil.g == -1
		|| cub3d->map.col_ceil.b == -1)
		return (ft_dprintf(2, "error: bad ceiling color\n"), EXIT_FAILURE);
	if (cub3d->map.m == NULL)
		return (ft_dprintf(2, "error: missing map\n"), EXIT_FAILURE);
	if (cub3d->player.x == -1 || cub3d->player.y == -1)
		return (ft_dprintf(2, "error: missing player\n"), EXIT_FAILURE);
	if (check_parsing_map(cub3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
