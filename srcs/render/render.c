/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:41:19 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/05 13:30:59 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render(t_cub3d *cub3d)
{
	if (cub3d->game.page == LANDING_PAGE)
		render_landing_page(cub3d);
	else if (cub3d->game.page == GAME_PAGE)
		render_game_page(cub3d);
	else
		render_exit_page(cub3d);
	return (EXIT_SUCCESS);
}
