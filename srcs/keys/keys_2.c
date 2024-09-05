/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:27:13 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/05 18:44:01 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	minimap_keys(t_cub3d *cub3d, int keycode)
{
	if (keycode == k_zoom_out)
	{
		if (cub3d->game.minimap_size > 60)
			cub3d->game.minimap_size = 60;
		else
			cub3d->game.minimap_size++;
	}
	if (keycode == k_zoom_in)
	{
		if (cub3d->game.minimap_size < 2)
			cub3d->game.minimap_size = 2;
		cub3d->game.minimap_size--;
	}
}
