/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:24:25 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/08 15:42:04 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	monster_is_present(t_cub3d *cub, t_pointd pos)
{
	t_monsters	*m;

	m = cub->monsters;
	while (m)
	{
		if ((int)m->pos.x == (int)pos.x && (int)m->pos.y == (int)pos.y)
			return (true);
		m = m->next;
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

static void lateral_move(t_cub3d *cub, t_monsters *m, int random)
{
	if (is_wall(cub, m->pos.x + cub->game.m_speed, m->pos.y + cub->game.m_speed) == false && random == 4)
	{
		m->pos.x += cub->game.m_speed;
		m->pos.y += cub->game.m_speed;
	}
	else if (is_wall(cub, m->pos.x - cub->game.m_speed, m->pos.y + cub->game.m_speed) == false && random == 5)
	{
		m->pos.x -= cub->game.m_speed;
		m->pos.y += cub->game.m_speed;
	}
	else if (is_wall(cub, m->pos.x + cub->game.m_speed, m->pos.y - cub->game.m_speed) == false && random == 6)
	{
		m->pos.x += cub->game.m_speed;
		m->pos.y -= cub->game.m_speed;
	}
	else if (is_wall(cub, m->pos.x - cub->game.m_speed, m->pos.y - cub->game.m_speed) == false && random == 7)
	{
		m->pos.x -= cub->game.m_speed;
		m->pos.y -= cub->game.m_speed;
	}
}

static void	movement_monster(t_cub3d *cub, t_monsters *m)
{
	static int i = 0;

	if (i > 50)
	{
		i = 0;
		m->random = rand() % 8;
	}
	if (is_wall(cub, m->pos.x + cub->game.m_speed, m->pos.y) == false && m->random == 0)
		m->pos.x += cub->game.m_speed;
	else if (m->random == 0)
		m->random = rand() % 3 + 1;
	if (is_wall(cub, m->pos.x, m->pos.y + cub->game.m_speed) == false && m->random == 1)
		m->pos.y += cub->game.m_speed;
	else if (m->random == 1)
		m->random = rand() % 2 + 2;
	if (is_wall(cub, m->pos.x - cub->game.m_speed, m->pos.y) == false && m->random == 2)
		m->pos.x -= cub->game.m_speed;
	else if (m->random == 2)
		m->random = rand() % 1 + 3;
	if (is_wall(cub, m->pos.x, m->pos.y - cub->game.m_speed) == false && m->random == 3)
		m->pos.y -= cub->game.m_speed;
	else if (m->random == 3)
		m->random = rand() % 4;
	lateral_move(cub, m, m->random);
	i++;
}

void	move_monsters(t_cub3d *cub)
{
	t_monsters				*m;
	static struct timeval	old_time = {.tv_sec = 0, .tv_usec = 0};
	struct timeval			m_time;

	if (old_time.tv_sec == 0)
		gettimeofday(&old_time, NULL);
	gettimeofday(&m_time, NULL);
	if (labs(m_time.tv_usec - old_time.tv_usec) > 100000)
	{
		old_time = m_time;
		m = cub->monsters;
		while (m)
		{
			old_time = cub->game.last_time;
			movement_monster(cub, m);
			m = m->next;
		}
	}
	add_monster_time(cub);
}
