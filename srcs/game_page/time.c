/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:38:59 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/13 10:37:50 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Met à jour le temps du jeu ('time') et le temps ecoulé depuis le precedent
* appel: 'frame_time'
*/
void	update_time(t_game *g)
{
	struct timeval	tod;

	gettimeofday(&tod, NULL);
	g->frame_time = tod.tv_sec - g->last_tod.tv_sec
		+ 1e-6 * (tod.tv_usec - g->last_tod.tv_usec);
	g->last_tod = tod;
	g->time += g->frame_time;
}
