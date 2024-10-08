/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:22:41 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/18 12:08:33 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Attention: tous les appels à libmlx qui modifient le contenu de la fenetre
 * d'affichage ne sont executés qu'au retour de notre callback (hook) de render.
 * Donc toute modification du buffer de rendu (mlx_img) meme après l'appel
 * à mlx_put_image_to_window() impactera l'affichage puisque la copie de mlx_img
 * ne surviendra qu'au retour de notre fonction.
 *  -> draw_hud() modifie mlx_img donc le hud s'affiche bien.
*/

int	render_game_page(t_cub3d *cub)
{
	update_player_pos(cub);
	mlx_put_image_to_window(cub->mlx.mlx_ptr, cub->mlx.win_ptr,
		cub->mlx.mlx_img.ptr, 0, 0);
	render_frame(cub);
	update_time(&cub->game);
	draw_fps(cub);
	return (0);
}
