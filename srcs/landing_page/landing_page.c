/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   landing_page.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:21:37 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/28 15:17:52 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	render_landing_page(t_cub3d *cub3d)
{
	mlx_string_put(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, 1000, 500, 0xFFFFFF,
		"Press Space to start");
	return (0);
}
