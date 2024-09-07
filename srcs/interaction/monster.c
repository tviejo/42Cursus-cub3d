/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:24:25 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/07 22:08:40 by tviejo           ###   ########.fr       */
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

static void lateral_move(t_cub3d *cub, t_monsters *tmp, int random)
{
	if (is_wall(cub, tmp->pos.x + cub->game.m_speed, tmp->pos.y + cub->game.m_speed) == false && random == 4)
	{
		tmp->pos.x += cub->game.m_speed;
		tmp->pos.y += cub->game.m_speed;
	}
	else if (is_wall(cub, tmp->pos.x - cub->game.m_speed, tmp->pos.y + cub->game.m_speed) == false && random == 5)
	{
		tmp->pos.x -= cub->game.m_speed;
		tmp->pos.y += cub->game.m_speed;
	}
	else if (is_wall(cub, tmp->pos.x + cub->game.m_speed, tmp->pos.y - cub->game.m_speed) == false && random == 6)
	{
		tmp->pos.x += cub->game.m_speed;
		tmp->pos.y -= cub->game.m_speed;
	}
	else if (is_wall(cub, tmp->pos.x - cub->game.m_speed, tmp->pos.y - cub->game.m_speed) == false && random == 7)
	{
		tmp->pos.x -= cub->game.m_speed;
		tmp->pos.y -= cub->game.m_speed;
	}
}

static void	movement_monster(t_cub3d *cub, t_monsters *tmp)
{
	static int i = 0;

	if (i > 50)
	{
		i = 0;
		tmp->random = rand() % 8;
	}
	if (is_wall(cub, tmp->pos.x + cub->game.m_speed, tmp->pos.y) == false && tmp->random == 0)
		tmp->pos.x += cub->game.m_speed;
	else if (tmp->random == 0)
		tmp->random = rand() % 3 + 1;
	if (is_wall(cub, tmp->pos.x, tmp->pos.y + cub->game.m_speed) == false && tmp->random == 1)
		tmp->pos.y += cub->game.m_speed;
	else if (tmp->random == 1)
		tmp->random = rand() % 2 + 2;
	if (is_wall(cub, tmp->pos.x - cub->game.m_speed, tmp->pos.y) == false && tmp->random == 2)
		tmp->pos.x -= cub->game.m_speed;
	else if (tmp->random == 2)
		tmp->random = rand() % 1 + 3;
	if (is_wall(cub, tmp->pos.x, tmp->pos.y - cub->game.m_speed) == false && tmp->random == 3)
		tmp->pos.y -= cub->game.m_speed;
	else if (tmp->random == 3)
		tmp->random = rand() % 4;
	lateral_move(cub, tmp, tmp->random);
	i++;
}

void	move_monster(t_cub3d *cub)
{
	t_monsters				*tmp;
	static struct timeval	old_time = {.tv_sec = 0, .tv_usec = 0};
	struct timeval			tmp_time;

	if (old_time.tv_sec == 0)
		gettimeofday(&old_time, NULL);
	gettimeofday(&tmp_time, NULL);
	if (labs(tmp_time.tv_usec - old_time.tv_usec) > 100000)
	{
		old_time = tmp_time;
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
