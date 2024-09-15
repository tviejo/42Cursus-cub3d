/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:00:53 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/15 11:29:31 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ads_gfx.h"

/* returns the time as the number of milliseconds since the Epoch,
 * 1970-01-01 00:00:00 +0000 (UTC).
*/
t_time_ms	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

/* renvoie la durée ecoulée depuis time0
*/
t_duree_ms	get_duree(t_time_ms time0)
{
	return (get_time() - time0);
}

/* renvoie la durée ecoulée depuis time0
 * et met à jour time0 avec le temps actuel
*/
t_duree_ms	get_duree_update_t0(t_time_ms *time0)
{
	t_duree_ms	duree;

	duree = get_time() - *time0;
	*time0 += duree;
	return (duree);
}
