/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:22:41 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/12 10:30:09 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Attention: tous les appels à libmlx qui modifient le contenu de la fenetre
 * d'affichage ne sont executés qu'au retour de notre callback (hook) de render.
 * Donc toute modification du buffer de rendu (mlx_img) meme après l'appel
 * à mlx_put_image_to_window() impactera l'affichage puisque la copie de mlx_img
 * ne surviendra qu'au retour de notre fonction.
 *  -> draw_hud() modifie mlx_img donc le hud s'affiche bien !
*/
int	render_game_page(t_cub3d *cub3d)
{
	update_player_pos(cub3d);
	update_health(cub3d);
	mlx_put_image_to_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr,
		cub3d->mlx.mlx_img.ptr, 0, 0);
	render_frame(cub3d);
	draw_monsters(cub3d);
	draw_minimap(cub3d);
	interact_door(cub3d, cub3d->player.pos);
	move_monsters(cub3d);
	shoot_monsters(cub3d);
	sound_close_monster(cub3d);
	update_time_n_draw_fps(cub3d);
	reload(cub3d);
	draw_hud(cub3d);
	return (0);
}
