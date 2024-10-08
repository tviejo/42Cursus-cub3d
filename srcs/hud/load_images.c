/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 01:28:04 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/12 00:13:53 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_hud_textures(t_cub3d *c)
{
	t_image *const	tx = c->mlx.text;
	void *const		mlxptr = c->mlx.mlx_ptr;

	if (load_texture(mlxptr, IMG_GUN, &tx[TXID_GUN]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_texture(mlxptr, IMG_FIRE, &tx[TXID_FIRE]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_texture(mlxptr, IMG_RELOAD, &tx[TXID_GUN_RELOAD])
		== EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_texture(mlxptr, IMG_GAME_OVER, &tx[TXID_GAME_OVER])
		== EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_texture(mlxptr, IMG_LANDING, &tx[TXID_LANDING])
		== EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_texture(mlxptr, IMG_EXIT, &tx[TXID_EXIT]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
