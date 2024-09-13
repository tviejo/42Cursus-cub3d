/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:54:06 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/13 18:34:51 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void	tryfire(t_cub3d *cub)
{	
	if (cub->player.ammo > 0 && cub->inputs.reload == false)
	{
		cub->inputs.shoot = true;
		cub->inputs.has_fired = true;
		cub->player.ammo--;
		play_sound(SND_SHOOT, cub);
	}
	else
		play_sound(SND_EMPTY, cub);
}
