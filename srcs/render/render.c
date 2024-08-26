/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:41:19 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/26 15:13:04 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	render(t_cub3d *cub3d)
{
	mlx_clear_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr);
	if (cub3d->game.page == LANDING_PAGE)
		render_landing_page(cub3d);
	else if (cub3d->game.page == GAME_PAGE)
		render_game_page(cub3d);
	else
		render_exit_page(cub3d);
	return (EXIT_SUCCESS);
}