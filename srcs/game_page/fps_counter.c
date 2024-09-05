/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:53:44 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/05 18:57:19 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_frame_time(t_game *g, struct timeval time)
{
	g->frame_time = time.tv_sec - g->last_time.tv_sec
		+ 1e-6 * (time.tv_usec - g->last_time.tv_usec);
	g->last_time = time;
}

static void	print(t_cub3d *cub3d, char *str, int fps, t_point pos)
{
	char	*fps_str;
	char	*fps_value;

	fps_value = ft_itoa(fps);
	fps_str = ft_strjoin(str, fps_value);
	mlx_string_put(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, pos.x, pos.y,
		COL_BLACK, fps_str);
	free(fps_str);
	free(fps_value);
}

void	print_moy_fps(t_cub3d *cub3d, int fps, int frame)
{
	static long int	sum_fps = 300;
	static long int	sec_counter = 0;
	static int		moy_fps = 0;

	if (frame == 1)
	{
		if (sec_counter > INT_MAX || sum_fps > INT_MAX)
		{
			sec_counter = 0;
			sum_fps = 0;
		}
		sec_counter++;
		sum_fps += fps;
		moy_fps = sum_fps / sec_counter;
	}
	print(cub3d, "Moy FPS: ", moy_fps, (t_point){{1825}, {40}});
}

void	print_fps(t_cub3d *cub3d, int fps)
{
	print(cub3d, "FPS: ", fps, (t_point){{1850}, {20}});
}

void	update_n_draw_fps(t_cub3d *cub3d)
{
	struct timeval	current_time;
	static int		frame = 0;
	static int		last_fps = 0;
	static int		last_sec = 0;

	gettimeofday(&current_time, NULL);
	update_frame_time(&cub3d->game, current_time);
	if (current_time.tv_sec != last_sec)
	{
		last_fps = frame;
		frame = 0;
		last_sec = current_time.tv_sec;
	}
	frame++;
	print_fps(cub3d, last_fps);
	print_moy_fps(cub3d, last_fps, frame);
}
