/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:24:25 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/07 18:37:01 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	monster_is_present(t_cub3d *cub, t_pointd pos)
{
	t_monsters	*tmp;

	tmp = cub->monsters;
	while (tmp)
	{
		if ((int)tmp->pos.x == (int)pos.x && (int)tmp->pos.y == (int)pos.y)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

static void	add_monster_time(t_cub3d *cub)
{
	static struct timeval	old_time = {.tv_sec = 0, .tv_usec = 0};
	int						x;
	int						y;
	int						i;

	if (cub->game.last_time.tv_sec != old_time.tv_sec)
	{
		old_time = cub->game.last_time;
		i = 0;
		while (i < cub->game.dificulty)
		{
			x = rand() % cub->map.width;
			y = rand() % cub->map.height;
			if (cub->map.m[y][x] == '0')
				add_back_monster(cub, new_monster((t_pointd){.x = x + 0.5,
						.y = y + 0.5}, 100));
			i++;
		}
	}
}

static void	movement_monster(t_cub3d *cub, t_monsters *tmp)
{
	int	random;

	random = rand() % 4;
	if (is_wall(cub, tmp->pos.x + 0.5, tmp->pos.y) == false && random == 0)
		tmp->pos.x += 0.5;
	else if (is_wall(cub, tmp->pos.x, tmp->pos.y + 0.5) == false && random == 1)
		tmp->pos.y += 0.5;
	else if (is_wall(cub, tmp->pos.x - 0.5, tmp->pos.y) == false && random == 2)
		tmp->pos.x -= 0.5;
	else if (is_wall(cub, tmp->pos.x, tmp->pos.y - 0.5) == false && random == 3)
		tmp->pos.y -= 0.5;
}

void	move_monster(t_cub3d *cub)
{
	t_monsters				*tmp;
	static struct timeval	old_time = {.tv_sec = 0, .tv_usec = 0};

	if (cub->game.last_time.tv_sec - old_time.tv_sec != 0)
	{
		tmp = cub->monsters;
		while (tmp)
		{
			old_time = cub->game.last_time;
			movement_monster(cub, tmp);
			tmp = tmp->next;
		}
	}
	add_monster_time(cub);
}
