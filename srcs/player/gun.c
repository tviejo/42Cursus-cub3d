/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 22:06:57 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/15 14:57:58 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	reload(t_cub3d *cub3d)
{
	static struct timeval	last_time = {0, 0};
	static bool				sound_played = false;

	if (cub3d->inputs.reload == true)
	{
		if (sound_played == false)
		{
			play_sound(SND_RELOAD, cub3d);
			sound_played = true;
		}
		if (cub3d->player.ammo < NB_AMMO)
		{
			if (last_time.tv_sec == 0)
				gettimeofday(&last_time, NULL);
			if (cub3d->game.last_tod.tv_sec - last_time.tv_sec > 2)
			{
				cub3d->player.ammo = NB_AMMO;
				last_time = (struct timeval){0, 0};
				cub3d->inputs.reload = false;
				sound_played = false;
			}
		}
	}
}

void	tryfire(t_cub3d *cub)
{
	if (cub->game.time < cub->player.shoot_last_time + SHOOT_DELAY)
		return ;
	cub->player.shoot_last_time = cub->game.time;
	if (!cub->inputs.reload && cub->player.ammo > 0)
	{
		cub->inputs.shoot = true;
		cub->inputs.has_fired = true;
		cub->player.ammo--;
		play_sound(SND_SHOOT, cub);
	}
	else
		play_sound(SND_EMPTY, cub);
}

void	gunfire(t_cub3d *cub)
{
	if (cub->inputs.ms_fire || cub->inputs.k_fire_1 || cub->inputs.k_fire_2)
	{
		tryfire(cub);
	}
}
