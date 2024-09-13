/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:40:12 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/13 10:32:37 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_close_to_enemy(t_cub3d *cub)
{
	t_monsters	*m;
	t_pointd	pos;
	double		dist;
	int			i;
	int			j;

	m = cub->monsters;
	pos = cub->player.pos;
	while (m)
	{
		i = -2;
		while (++i <= 1)
		{
			j = -2;
			while (++j <= 1)
			{
				dist = sqrt(pow(m->pos.x + i - pos.x, 2) + pow(m->pos.y + j
							- pos.y, 2));
				if (dist < 0.5)
					return (true);
			}
		}
		m = m->next;
	}
	return (false);
}

void	update_health(t_cub3d *cub)
{
	static struct timeval	old_time = {.tv_sec = 0, .tv_usec = 0};

	if (cub->game.last_tod.tv_sec - old_time.tv_sec != 0)
	{
		old_time = cub->game.last_tod;
		if (is_close_to_enemy(cub))
		{
			cub->player.health -= 10;
			play_sound(SND_DAMAGE, cub);
		}
		else if (cub->player.health < 100)
			cub->player.health++;
	}
	if (cub->player.health <= 0)
	{
		play_sound(SND_YOU_DIED, cub);
		set_game_state(cub, GAME_OVER_PAGE);
	}
}
