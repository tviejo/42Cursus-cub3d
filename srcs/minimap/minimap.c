/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:07:14 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/26 15:52:21 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include  "../../includes/cub3d.h"

int minimap(t_cub3d *cub3d)
{
    size_t i;
    size_t j;

    i = 0;
    while (i < cub3d->parsing.map_height + 1)
    {
        j = 0;
        while (j < cub3d->parsing.map_with )
        {
            if (cub3d->parsing.map[i][j] == '1')
                mlx_pixel_put(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, j*10, i*10, 0xFF0000);
            else if (cub3d->parsing.map[i][j] == '0')
                mlx_pixel_put(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, j*10, i*10, 0x00FF00);
            else
                mlx_pixel_put(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, j*10, i*10, 0x000000);
            j++;
        }
        i++;
    }
    mlx_pixel_put(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, cub3d->player.y * 10, cub3d->player.x * 10, 0xFFFFFF);
    return (EXIT_SUCCESS);
}