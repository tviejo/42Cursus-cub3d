/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:27:27 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/25 16:37:17 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

int    mlx_start(t_cub3d *cub3d)
{
    cub3d->mlx.mlx_ptr = mlx_init();
    if (cub3d->mlx.mlx_ptr == NULL)
        return (EXIT_FAILURE);
    cub3d->mlx.win_ptr = mlx_new_window(cub3d->mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
    if (cub3d->mlx.win_ptr == NULL)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int     mlx_close(t_cub3d *cub3d)
{
    if (cub3d->mlx.pixel != NULL)
        ft_free_img(cub3d);
    if (cub3d->mlx.mlx_img != NULL)
        mlx_destroy_image(cub3d->mlx.mlx_ptr, cub3d->mlx.mlx_img);
    if (cub3d->mlx.win_ptr != NULL)
        mlx_destroy_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr);
    if (cub3d->mlx.mlx_ptr != NULL)
        mlx_destroy_display(cub3d->mlx.mlx_ptr);
    if (cub3d->mlx.mlx_ptr != NULL)
        free(cub3d->mlx.mlx_ptr);
    return (EXIT_SUCCESS);
}