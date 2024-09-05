/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:22:34 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/05 14:08:43 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_exit_page(t_cub3d *cub3d)
{
	mlx_clear_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr);
	mlx_string_put(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, 950, 500, 0xFF0000,
		"Exit Page: y to exit, n to return");
	return (0);
}
