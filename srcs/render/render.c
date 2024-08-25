/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:41:19 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/25 18:32:13 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	render(t_cub3d *cub3d)
{
    render_background(cub3d, 0x555555);
	if (cub3d->game.page == LANDING_PAGE)
		render_landing_page(cub3d);
	else if (cub3d->game.page == GAME_PAGE)
		render_game_page(cub3d);
	else
		render_exit_page(cub3d);
	return (EXIT_SUCCESS);
}