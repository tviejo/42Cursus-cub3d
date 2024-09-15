/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:53:44 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/14 19:32:52 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print(t_cub3d *cub, char *str, int fps, t_point pos)
{
	char	*fps_str;
	char	*fps_value;

	fps_value = ft_itoa(fps);
	fps_str = ft_strjoin(str, fps_value);
	mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, pos.x, pos.y, COL_WHITE,
		fps_str);
	free(fps_str);
	free(fps_value);
}

static void	print_moy_fps(t_cub3d *cub, int fps, int frame)
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
	print(cub, "Moy FPS: ", moy_fps, (t_point){{cub->mlx.mlx_img.dim.width
		- 140}, {40}});
}

static void	print_fps(t_cub3d *cub, int fps)
{
	print(cub, "FPS: ", fps,
		(t_point){{cub->mlx.mlx_img.dim.width - 100}, {20}});
}

/* Fonction à réécrire en exploitant game.frame_time au lieu de faire
 * un nouvel appel à gettimeofday()
 */
void	draw_fps(t_cub3d *cub3d)
{
	struct timeval	current_time;
	static int		frame = 0;
	static int		last_fps = 0;
	static int		last_sec = 0;

	gettimeofday(&current_time, NULL);
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
