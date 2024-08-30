/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_create_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:51:28 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/30 14:03:25 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_free_img(t_mlx *mlx)
{
	int	i;
	int	size;

	size = WINDOW_WIDTH;
	if (WINDOW_HEIGHT > size)
		size = WINDOW_HEIGHT;
	if (mlx->pixel != NULL)
	{
		i = -1;
		while (++i < size)
			free(mlx->pixel[i]);
		free(mlx->pixel);
	}
	return (0);
}

int	ft_reset_img(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	size;

	size = WINDOW_WIDTH;
	if (WINDOW_HEIGHT > size)
		size = WINDOW_HEIGHT;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			cub3d->mlx.pixel[i][j] = 0;
	}
	return (0);
}

int	ft_init_img(t_cub3d *cub3d)
{
	int	i;
	int	size;

	size = WINDOW_WIDTH;
	if (WINDOW_HEIGHT > size)
		size = WINDOW_HEIGHT;
	if (cub3d->mlx.pixel == NULL)
	{
		cub3d->mlx.pixel = (int **)malloc((size + 1) * sizeof(int *));
		if (cub3d->mlx.pixel == NULL)
			return (ft_close(cub3d));
		i = -1;
		while (++i < size)
		{
			cub3d->mlx.pixel[i] = (int *)malloc((size + 1) * sizeof(int));
			if (cub3d->mlx.pixel[i] == NULL)
				return (ft_close(cub3d));
		}
	}
	ft_reset_img(cub3d);
	return (0);
}

int	mlx_create_img(t_cub3d *cub3d)
{
	t_image *const	img = &cub3d->mlx.mlx_img;

	img->ptr = mlx_new_image(cub3d->mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (img->ptr == NULL)
		return (EXIT_FAILURE);
	img->pixels = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_size,
			&img->endian);
	if (img->pixels == NULL)
		return (EXIT_FAILURE);
	img->dim.width = WINDOW_WIDTH;
	img->dim.height = WINDOW_HEIGHT;
	cub3d->mlx.pixel = NULL;
	//init_data_mlx(cub3d);
	ft_init_img(cub3d);
	return (EXIT_SUCCESS);
}
