/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_create_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:51:28 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/25 16:25:38 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

int     ft_free_img(t_cub3d *cub3d)
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

int     ft_reset_img(t_cub3d *cub3d)
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
int ft_init_img(t_cub3d *cub3d)
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

int     mlx_create_img(t_cub3d *cub3d)
{
    cub3d->mlx.mlx_img = mlx_new_image(cub3d->mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (cub3d->mlx.mlx_img == NULL)
        return (EXIT_FAILURE);
    cub3d->mlx.addr = mlx_get_data_addr(cub3d->mlx.mlx_img, &cub3d->mlx.bpp,
			&cub3d->mlx.line_len, &cub3d->mlx.endian);
    if (cub3d->mlx.addr == NULL)
        return (EXIT_FAILURE);
    cub3d->mlx.pixel = NULL;
    init_data_mlx(cub3d);
    ft_init_img(cub3d);
    return (EXIT_SUCCESS);
}