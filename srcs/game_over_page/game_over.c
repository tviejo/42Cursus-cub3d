/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:49:29 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/15 19:16:01 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_game_over_page(t_cub3d *c)
{
	t_image *const	img = &c->mlx.text[TXID_GAME_OVER];

	img_clear128(&c->mlx.mlx_img);
	draw_image_autoscale(img, &c->mlx.mlx_img);
	mlx_put_image_to_window(c->mlx.mlx_ptr, c->mlx.win_ptr, c->mlx.mlx_img.ptr,
		0, 0);
	return (0);
}
