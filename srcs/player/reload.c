/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 22:06:57 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/10 12:21:10 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	reload(t_cub3d *cub3d)
{
	static struct timeval	last_time = {0, 0};
	static bool sound_played = false;

	if (cub3d->inputs.reload == true)
	{
		if (sound_played == false)
		{
			play_sound(RELOAD_SOUND, cub3d);
			sound_played = true;
		}
		if (cub3d->player.ammo < 10)
		{
			if (last_time.tv_sec == 0)
				gettimeofday(&last_time, NULL);
			if (cub3d->game.last_time.tv_sec - last_time.tv_sec > 2)
			{
				cub3d->player.ammo = 10;
				last_time = (struct timeval){0, 0};
				cub3d->inputs.reload = false;
				sound_played = false;
			}
		}
	}
}
