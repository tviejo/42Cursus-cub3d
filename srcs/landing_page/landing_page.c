/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   landing_page.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:21:37 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/15 13:56:54 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// if (MOUSE == 1)
//	mlx_mouse_show(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr);

int	render_landing_page(t_cub3d *c)
{
	t_image const	*img = &c->mlx.text[TXID_LANDING];
	const t_size2i	win = {.width = c->mlx.mlx_img.dim.width,
		.height = c->mlx.mlx_img.dim.height};
	int				xpos;
	int				ypos;
	char			*difficulty;

	mlx_clear_window(c->mlx.mlx_ptr, c->mlx.win_ptr);
	xpos = (win.width - img->dim.width) >> 1;
	ypos = (win.height - img->dim.height) >> 1;
	mlx_put_image_to_window(c->mlx.mlx_ptr, c->mlx.win_ptr, img->ptr,
		xpos, ypos);
	mlx_string_put(c->mlx.mlx_ptr, c->mlx.win_ptr, win.width - 350,
		win.height - 60, 0xFFFFFF, "Choose difficulty: ");
	difficulty = ft_itoa(c->game.difficulty);
	mlx_string_put(c->mlx.mlx_ptr, c->mlx.win_ptr, win.width - 165,
		win.height - 60, 0xFFFFFF, difficulty);
	free(difficulty);
	return (0);
}
