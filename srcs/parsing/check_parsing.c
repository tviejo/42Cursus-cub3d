/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:57:50 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/26 14:48:23 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool value(t_cub3d *cub3d, size_t i, size_t j)
{
	if (cub3d->parsing.map[i][j] == '0')
		return (true);
	if (cub3d->parsing.map[i][j] == 'N')
		return (true);
	if (cub3d->parsing.map[i][j] == 'S')
		return (true);
	if (cub3d->parsing.map[i][j] == 'E')
		return (true);
	if (cub3d->parsing.map[i][j] == 'W')
		return (true);
	return (false);
}
static bool check(t_cub3d *cub3d, size_t i, size_t j)
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
	if (cub3d->parsing.map[i + 1] && value(cub3d, i + 1, j) == true)
	{
		ft_dprintf(2, "error: map invalid at %d,%d\n", i + 1, j);
		return (EXIT_FAILURE);
	}
	if (cub3d->parsing.map[i][j + 1] && value(cub3d, i, j + 1) == true)
	{
		ft_dprintf(2, "error: map invalid at %d,%d\n", i, j + 1);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
int	check_parsing_map(t_cub3d *cub3d)
{
    size_t i;
	size_t j;

	i = 0;
	while (i < cub3d->parsing.map_height + 2)
	{
		j = 0;
		while (cub3d->parsing.map[i][j])
		{
			if (cub3d->parsing.map[i][j] == '9')
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
	if (cub3d->parsing.map_height == 0 || cub3d->parsing.map_with == 0)
		return (ft_dprintf(2, "error: missing map\n"),EXIT_FAILURE);
	if (cub3d->parsing.no == NULL || cub3d->parsing.so == NULL || cub3d->parsing.we == NULL
		|| cub3d->parsing.ea == NULL)
		return (ft_dprintf(2, "error: missing texture\n"),EXIT_FAILURE);
	if (cub3d->parsing.floor.r == -1 || cub3d->parsing.floor.g == -1 || cub3d->parsing.floor.b == -1)
		return (ft_dprintf(2, "error: bad floor color\n"),EXIT_FAILURE);
	if (cub3d->parsing.cei.r == -1 || cub3d->parsing.cei.g == -1 || cub3d->parsing.cei.b == -1)
		return (ft_dprintf(2, "error: bad ceiling color\n"), EXIT_FAILURE);
	if (cub3d->parsing.map == NULL)
		return (ft_dprintf(2, "error: missing map\n"),EXIT_FAILURE);
	if (check_parsing_map(cub3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}