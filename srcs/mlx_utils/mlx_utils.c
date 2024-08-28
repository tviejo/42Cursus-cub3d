/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:27:27 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/28 15:30:29 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	mlx_start(t_cub3d *cub3d)
{
	cub3d->mlx.mlx_ptr = mlx_init();
	if (cub3d->mlx.mlx_ptr == NULL)
		return (EXIT_FAILURE);
	cub3d->mlx.win_ptr = mlx_new_window(cub3d->mlx.mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "cub3d");
	if (cub3d->mlx.win_ptr == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	mlx_close(t_cub3d *cub3d)
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

void	img_pix_put(t_cub3d *cub3d, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
	{
		i = cub3d->mlx.bpp - 8;
		pixel = cub3d->mlx.pixels
			+ y * cub3d->mlx.line_size + x * (cub3d->mlx.bpp / 8);
		while (i >= 0)
		{
			if (cub3d->mlx.endian != 0)
				*pixel++ = (color >> i) & 0xFF;
			else
				*pixel++ = (color >> (cub3d->mlx.bpp - 8 - i)) & 0xFF;
			i -= 8;
		}
	}
}

/*
void	render_background(t_cub3d *cub3d, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(cub3d, j, i, color);
			cub3d->mlx.pixel[i][j] = 0;
			j++;
		}
		++i;
	}
	mlx_put_image_to_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr,
		cub3d->mlx.mlx_img, 0, 0);
}
*/
