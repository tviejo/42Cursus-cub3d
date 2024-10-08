/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:26:41 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/13 17:52:55 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_door_state	door_present(t_cub3d *cub)
{
	t_scaninfo	info;

	scan_in_front(cub, &info, 0);
	if (cub->map.m[(int)info.mpos.y][(int)info.mpos.x] == 'C')
	{
		if (info.distance < 1.5)
			return (DOOR_CLOSED);
	}
	else if (cub->map.m[(int)info.mpos.y][(int)info.mpos.x] == 'O')
	{
		if (info.distance < 1.5)
			return (DOOR_OPENED);
	}
	return (NO_DOOR);
}

static int	moove_door(t_cub3d *cub, t_pointd pos)
{
	t_scaninfo	si;

	(void)pos;
	scan_in_front(cub, &si, 0);
	if (si.item == 'C')
	{
		play_sound(SND_DOOR_OPEN, cub);
		cub->map.m[si.mpos.y][si.mpos.x] = 'O';
	}
	else if (si.item == 'O')
	{
		play_sound(SND_DOOR_CLOSE, cub);
		cub->map.m[si.mpos.y][si.mpos.x] = 'C';
	}
	return (EXIT_FAILURE);
}

int	interact_door(t_cub3d *cub, t_pointd pos)
{
	if (cub->inputs.open && door_present(cub) != NO_DOOR)
	{
		moove_door(cub, pos);
		cub->inputs.open = false;
		cub->inputs.k_open_1 = false;
		cub->inputs.k_open_2 = false;
	}
	else if (door_present(cub) != NO_DOOR)
	{
		if (door_present(cub) == DOOR_CLOSED)
			mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, 880, 1000,
				COL_WHITE, "Press E to open the door");
		else
			mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, 880, 1000,
				COL_WHITE, "Press E to close the door");
	}
	return (EXIT_FAILURE);
}
