/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:41:19 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/30 14:11:48 by ade-sarr         ###   ########.fr       */
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
