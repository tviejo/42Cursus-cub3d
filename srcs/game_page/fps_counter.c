/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:53:44 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/26 19:04:05 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void   print_fps(int last_fps, t_cub3d *cub3d)
{
    char *fps;

    fps = ft_strjoin("FPS: ", ft_itoa(last_fps));
    mlx_string_put(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, 1850, 20, 0x00FFFFFF, fps);
    free(fps);
}

void   fps_counter(t_cub3d *cub3d)
{
    struct timeval current_time;
    static int  fps = 0;
    static int  last_fps = 0;
    static int  last_time = 0;

    gettimeofday(&current_time, NULL);
    if (current_time.tv_sec != last_time)
    {
        last_fps = fps;
        fps = 0;
        last_time = current_time.tv_sec;
    }
    fps++;
    print_fps(last_fps, cub3d);
}