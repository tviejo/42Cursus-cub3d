/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:53:44 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/26 19:40:46 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

static void print(int fps, t_cub3d *cub3d)
{
    char *fps_str;
    char *fps_counter;

    fps_counter = ft_itoa(fps);
    fps_str = ft_strjoin("Moy FPS: ", fps_counter);
    mlx_string_put(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, 1825, 40, 0x00FFFFFF, fps_str);
    free(fps_str);
    free(fps_counter);
}

void  print_moy_fps(int last_fps, t_cub3d *cub3d, int fps_current)
{
    static long int moy_fps = 300;
    static long int fps_counter = 0;
    static int print_fps = 0;

    if (fps_current == 1)
    {
        if (fps_counter > INT_MAX || moy_fps > INT_MAX)
        {
            fps_counter = 0;
            moy_fps = 0;
        }
        fps_counter++;
        moy_fps += last_fps;
        print_fps = moy_fps / fps_counter;
    }
    print(print_fps, cub3d);
}

void   print_fps(int last_fps, t_cub3d *cub3d)
{
    char *fps;
    char *fps_counter;

    fps_counter = ft_itoa(last_fps);
    fps = ft_strjoin("FPS: ", fps_counter);
    mlx_string_put(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, 1850, 20, 0x00FFFFFF, fps);
    free(fps);
    free(fps_counter);
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
    print_moy_fps(last_fps, cub3d, fps);
}