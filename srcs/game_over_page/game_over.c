/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:49:29 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/15 13:58:56 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_game_over_page(t_cub3d *c)
{
	t_image const	*img = &c->mlx.text[TXID_GAME_OVER];
	int				xpos;
	int				ypos;

	mlx_clear_window(c->mlx.mlx_ptr, c->mlx.win_ptr);
	xpos = (c->mlx.mlx_img.dim.width - img->dim.width) >> 1;
	ypos = (c->mlx.mlx_img.dim.height - img->dim.height) >> 1;
	mlx_put_image_to_window(c->mlx.mlx_ptr, c->mlx.win_ptr, img->ptr,
		xpos, ypos);
	return (0);
}
