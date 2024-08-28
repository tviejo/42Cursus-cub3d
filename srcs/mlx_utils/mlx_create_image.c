/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_create_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:51:28 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/28 18:39:08 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_free_img(t_cub3d *cub3d)
{
	int	i;
	int	size;

	size = WINDOW_WIDTH;
	if (WINDOW_HEIGHT > size)
		size = WINDOW_HEIGHT;
	if (cub3d->mlx.pixel != NULL)
	{
		i = -1;
		while (++i < size)
			free(cub3d->mlx.pixel[i]);
		free(cub3d->mlx.pixel);
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
	t_mlx *const	m = &cub3d->mlx;

	m->mlx_img = mlx_new_image(m->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (m->mlx_img == NULL)
		return (EXIT_FAILURE);
	m->pixels = mlx_get_data_addr(m->mlx_img, &m->bpp, &m->line_size,
			&m->endian);
	if (m->pixels == NULL)
		return (EXIT_FAILURE);
	m->width = WINDOW_WIDTH;
	m->height = WINDOW_HEIGHT;
	m->pixel = NULL;
	init_data_mlx(cub3d);
	ft_init_img(cub3d);
	return (EXIT_SUCCESS);
}
