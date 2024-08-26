/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:22:41 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/26 17:01:16 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

int render_game_page(t_cub3d *cub3d)
{
    mlx_clear_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr);
    update_player_pos(cub3d);
    minimap(cub3d);
    mlx_put_image_to_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, cub3d->mlx.mlx_img, 0, 0);
    return (0);
}