/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:57:27 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/03 07:00:57 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_directions	get_wall_orientation(double ray_angle, bool vertical_wall)
{
	if (vertical_wall)
	{
		if (ray_angle > NORTH_ANGLE && ray_angle < SOUTH_ANGLE)
			return (West);
		else
			return (East);
	}
	else
	{
		if (ray_angle < WEST_ANGLE)
			return (North);
		else
			return (South);
	}
}

int	get_wall_color(t_directions orientation, double distance, int wallitem)
{
	static const int	colors[] = {0xf70020, 0x7f3000, 0x0050ff, 0x000070};
	int					c;
	double				fade;

	c = colors[orientation];
	if (wallitem == 'C')
		c = COL_MAGENTA;
	fade = 6.0 / (6.0 + distance);
	c = ((int)(((c >> 16) & 255) * fade) << 16)
		+ ((int)(((c >> 8) & 255) * fade) << 8)
		+ (int)((c & 255) * fade);
	return (c);
}

//m = x - (float)(int)x;
//m += (float)(m<0.f);
// branchless form to add one if m is negative but not zero
