/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:57:50 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/25 14:44:00 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_parsing_map(t_cub3d *cub3d)
{
    if (cub3d->parsing.map[0] == NULL)
        return (EXIT_FAILURE);
    else
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
		return (ft_dprintf(2, "error: bad map\n"),EXIT_FAILURE);
	return (EXIT_SUCCESS);
}