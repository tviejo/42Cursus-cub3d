/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:27:27 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/30 14:03:38 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mlx_start(t_cub3d *cub3d)
{
	cub3d->mlx.mlx_ptr = mlx_init();
	if (cub3d->mlx.mlx_ptr == NULL)
		return (EXIT_FAILURE);
	cub3d->mlx.win_ptr = mlx_new_window(cub3d->mlx.mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "cub3D");
	if (cub3d->mlx.win_ptr == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	mlx_free_textures(t_mlx *mlx)
{
	if (mlx->text_north.ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->text_north.ptr);
	if (mlx->text_south.ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->text_south.ptr);
	if (mlx->text_west.ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->text_west.ptr);
	if (mlx->text_east.ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->text_east.ptr);
}

int	mlx_close(t_mlx *mlx)
{
	mlx_free_textures(mlx);
	if (mlx->pixel != NULL)
		ft_free_img(mlx);
	if (mlx->mlx_img.ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->mlx_img.ptr);
	if (mlx->win_ptr != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr != NULL)
		mlx_destroy_display(mlx->mlx_ptr);
	if (mlx->mlx_ptr != NULL)
		free(mlx->mlx_ptr);
	return (EXIT_SUCCESS);
}

void	img_pix_put(t_image *img, t_uint x, t_uint y, int color)
{
	char	*pixel;
	int		i;

	if (x < (t_uint)img->dim.width && y < (t_uint)img->dim.height)
	{
		i = img->bpp - 8;
		pixel = img->pixels
			+ y * img->line_size + x * (img->bpp / 8);
		while (i >= 0)
		{
			if (img->endian != 0)
				*pixel++ = (color >> i) & 0xFF;
			else
				*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
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
