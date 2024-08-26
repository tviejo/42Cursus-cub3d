/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:22:41 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/26 15:37:01 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

int render_game_page(t_cub3d *cub3d)
{
    update_player_pos(cub3d);
    mlx_string_put(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, 1000, 500, 0xFFFFFF, "Game Page");
    minimap(cub3d);
    return (0);
}