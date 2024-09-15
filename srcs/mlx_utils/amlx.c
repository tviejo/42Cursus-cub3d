/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amlx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:53:56 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/15 12:10:24 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Enable window resizing between min and max dimensions
 * 'min': minimum size is set to (min.width, min.heigth)
 * 'max': maximum size is set to (max.width, max.heigth)
*/
void	x11_set_win_minmax(Display *display, Window window,
	t_size2i min, t_size2i max)
{
	XSizeHints	hints;
	long		toto;

	XGetWMNormalHints(display, window, &hints, &toto);
	hints.min_width = min.width;
	hints.min_height = min.height;
	hints.max_width = max.width;
	hints.max_height = max.height;
	hints.flags = PMinSize | PMaxSize;
	XSetWMNormalHints(display, window, &hints);
}

/* Enable window resizing
*/
void	amlx_enable_win_resizing(t_mlx *mlx, t_size2i min, t_size2i max)
{
	x11_set_win_minmax(((t_xvar *)mlx->mlx_ptr)->display,
		((t_win_list *)mlx->win_ptr)->window,
		min, max);
}

/* Recreates the image buffer used for rendering (app->img) to match the
 * actual app window size. If size not changed, it does nothing.
*/
void	amlx_update_img_size(t_cub3d *cub)
{
	t_mlx *const		mlx = &cub->mlx;
	XWindowAttributes	attr;

	XGetWindowAttributes(((t_xvar *)mlx->mlx_ptr)->display,
		((t_win_list *)mlx->win_ptr)->window,
		&attr);
	if (attr.width != mlx->mlx_img.dim.width
		|| attr.height != mlx->mlx_img.dim.height)
	{
		ft_free_img(mlx);
		if (mlx->mlx_img.ptr != NULL)
			mlx_destroy_image(mlx->mlx_ptr, mlx->mlx_img.ptr);
		if (mlx_create_img(cub, attr.width, attr.height) == EXIT_FAILURE)
			ft_close(cub,
				"amlx_update_img_size(): mlx_create_img() fails !\n");
		cub->player.view_height = 0.08 * cub->mlx.mlx_img.dim.height;
	}
}

/* Retrieve window size and write it to width and height 
*/
void	amlx_get_win_size(void *mlx_ptr, void *win_ptr, int *width, int *height)
{
	XWindowAttributes	attr;

	XGetWindowAttributes(((t_xvar *)mlx_ptr)->display,
		((t_win_list *)win_ptr)->window, &attr);
	*width = attr.width;
	*height = attr.height;
}
