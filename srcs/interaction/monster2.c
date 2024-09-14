/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:54:06 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/14 19:24:32 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	item_is_wall(int item)
{
	if (item == '1' || item == 'C' || item == '9')
		return (true);
	return (false);
}

bool	is_m_wall(t_cub3d *cub, double x, double y)
{
	int	item;

	item = cub->map.m[(int)y][(int)x];
	if (item_is_wall(item))
		return (true);
	item = cub->map.m[(int)y][(int)(x + M_HB)];
	if (item_is_wall(item))
		return (true);
	item = cub->map.m[(int)(y + M_HB)][(int)x];
	if (item_is_wall(item))
		return (true);
	item = cub->map.m[(int)(y)][(int)(x - M_HB)];
	if (item_is_wall(item))
		return (true);
	item = cub->map.m[(int)(y - M_HB)][(int)x];
	if (item_is_wall(item))
		return (true);
	return (false);
}
