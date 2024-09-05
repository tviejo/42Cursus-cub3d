/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:26:41 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/05 15:01:33 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_door_state	door_present(t_cub3d *cub, t_pointd pos)
{
	const int	x = (int)pos.x;
	const int	y = (int)pos.y;
	int			i;
	int			j;

	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			if (cub->map.m[y + i][x + j] == 'C' && (i != 0 || j != 0))
				return (DOOR_CLOSED);
			if (cub->map.m[y + i][x + j] == 'O' && (i != 0 || j != 0))
				return (DOOR_OPENED);
			j++;
		}
		i++;
	}
	return (NO_DOOR);
}

static int	moove_door(t_cub3d *cub, t_pointd pos)
{
	const int	x = (int)pos.x;
	const int	y = (int)pos.y;
	int			i;
	int			j;

	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			if (cub->map.m[y + i][x + j] == 'C' && (i != 0 || j != 0))
				cub->map.m[y + i][x + j] = 'O';
			else if (cub->map.m[y + i][x + j] == 'O' && (i != 0 || j != 0))
				cub->map.m[y + i][x + j] = 'C';
			j++;
		}
		i++;
	}
	return (EXIT_FAILURE);
}

int	interact_door(t_cub3d *cub, t_pointd pos)
{
	static struct timeval	last_open = {0, 0};
	struct timeval			current_time;

	if (cub->inputs.open && door_present(cub, pos) != NO_DOOR)
	{
		gettimeofday(&current_time, NULL);
		if ((int)current_time.tv_sec - (int)last_open.tv_sec > 1)
		{
			moove_door(cub, pos);
			last_open = current_time;
		}
		return (EXIT_SUCCESS);
	}
	else if (door_present(cub, pos) != NO_DOOR)
	{
		if (door_present(cub, pos) == DOOR_CLOSED)
			mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, 880, 1000,
				COL_WHITE, "Press Q to open the door");
		else
			mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, 880, 1000,
				COL_WHITE, "Press Q to close the door");
	}
	return (EXIT_FAILURE);
}
