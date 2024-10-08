/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_create_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:51:28 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/15 11:23:47 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_free_img(t_mlx *mlx)
{
	free(mlx->slices_zbuffer);
	return (0);
}

int	ft_init_img(t_mlx *mlx)
{
	mlx->slices_zbuffer = malloc(mlx->mlx_img.dim.width * sizeof(double));
	if (mlx->slices_zbuffer == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	mlx_create_img(t_cub3d *cub, int width, int height)
{
	t_image *const	img = &cub->mlx.mlx_img;

	img->ptr = mlx_new_image(cub->mlx.mlx_ptr, width, height);
	if (img->ptr == NULL)
		return (EXIT_FAILURE);
	img->pixels = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_size,
			&img->endian);
	if (img->pixels == NULL)
		return (EXIT_FAILURE);
	img->dim.width = width;
	img->dim.height = height;
	return (ft_init_img(&cub->mlx));
}
