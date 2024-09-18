/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:24:25 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/18 12:06:21 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	monster_is_present(t_cub3d *cub, t_pointd pos)
{
	t_monsters	*m;
	double		delta_x;
	double		delta_y;
	static int	i = 0;

	i++;
	m = cub->monsters;
	while (m)
	{
		delta_x = m->pos.x - pos.x;
		delta_y = m->pos.y - pos.y;
		if (fabs(delta_x) < M_HIT_BOX && fabs(delta_y) < M_HIT_BOX)
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

	if (cub->game.last_tod.tv_sec != old_time.tv_sec)
	{
		old_time = cub->game.last_tod;
		i = 0;
		while (i < cub->game.difficulty)
		{
			x = rand() % cub->map.width;
			y = rand() % cub->map.height;
			if (cub->map.m[y][x] == '0')
				add_back_monster(cub, new_monster((t_pointd){.x = x + 0.5,
						.y = y + 0.5}, M_HP));
			i++;
		}
	}
}

static void	lateral_move(t_cub3d *cub, t_monsters *m, int random)
{
	if (is_m_wall(cub, m->pos.x + cub->game.m_speed, m->pos.y
			+ cub->game.m_speed) == false && random == 4)
	{
		m->pos.x += cub->game.m_speed;
		m->pos.y += cub->game.m_speed;
	}
	else if (is_m_wall(cub, m->pos.x - cub->game.m_speed, m->pos.y
			+ cub->game.m_speed) == false && random == 5)
	{
		m->pos.x -= cub->game.m_speed;
		m->pos.y += cub->game.m_speed;
	}
	else if (is_m_wall(cub, m->pos.x + cub->game.m_speed, m->pos.y
			- cub->game.m_speed) == false && random == 6)
	{
		m->pos.x += cub->game.m_speed;
		m->pos.y -= cub->game.m_speed;
	}
	else if (is_m_wall(cub, m->pos.x - cub->game.m_speed, m->pos.y
			- cub->game.m_speed) == false && random == 7)
	{
		m->pos.x -= cub->game.m_speed;
		m->pos.y -= cub->game.m_speed;
	}
}

static void	movement_monster(t_cub3d *c, t_monsters *m)
{
	static int	i = 0;

	if (i > 30)
	{
		i = 0;
		m->random = rand() % 8;
	}
	if (!is_m_wall(c, m->pos.x + c->game.m_speed, m->pos.y) && m->random == 0)
		m->pos.x += c->game.m_speed;
	else if (m->random == 0)
		m->random = rand() % 3 + 1;
	if (!is_m_wall(c, m->pos.x, m->pos.y + c->game.m_speed) && m->random == 1)
		m->pos.y += c->game.m_speed;
	else if (m->random == 1)
		m->random = rand() % 2 + 2;
	if (!is_m_wall(c, m->pos.x - c->game.m_speed, m->pos.y) && m->random == 2)
		m->pos.x -= c->game.m_speed;
	else if (m->random == 2)
		m->random = rand() % 1 + 3;
	if (!is_m_wall(c, m->pos.x, m->pos.y - c->game.m_speed) && m->random == 3)
		m->pos.y -= c->game.m_speed;
	else if (m->random == 3)
		m->random = rand() % 4 + 4;
	lateral_move(c, m, m->random);
	i++;
}

void	move_monsters(t_cub3d *cub)
{
	t_monsters				*m;
	static struct timeval	old_time = {.tv_sec = 0, .tv_usec = 0};
	struct timeval			m_time;
	t_pointd				old_pos;

	if (cub->game.m_freeze)
		return ;
	if (old_time.tv_sec == 0)
		gettimeofday(&old_time, NULL);
	gettimeofday(&m_time, NULL);
	if (ft_labs(m_time.tv_usec - old_time.tv_usec) > 100000)
	{
		old_time = m_time;
		m = cub->monsters;
		while (m)
		{
			old_time = cub->game.last_tod;
			old_pos = m->pos;
			while (old_pos.x == m->pos.x && old_pos.y == m->pos.y)
				movement_monster(cub, m);
			m = m->next;
		}
	}
	add_monster_time(cub);
}
