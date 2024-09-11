/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 01:28:04 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/11 21:28:24 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_hud_textures(t_cub3d *c)
{
	t_image *const	tx = c->mlx.text;
	void *const		mlxptr = c->mlx.mlx_ptr;

	if (load_texture(mlxptr, GUN_TEXTURE, &tx[TXID_GUN]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_texture(mlxptr, FIRE_TEXTURE, &tx[TXID_FIRE]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_texture(mlxptr, RELOAD_TEXTURE, &tx[TXID_GUN_RELOAD])
		== EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_texture(mlxptr, GAME_OVER_TEXTURE, &tx[TXID_GAME_OVER])
		== EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_texture(mlxptr, LANDING_TEXTURE, &tx[TXID_LANDING])
		== EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_texture(mlxptr, EXIT_TEXTURE, &tx[TXID_EXIT]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
