/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:39:20 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/02 18:23:35 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_player *p, double angle)
{
	p->dir += angle;
	while (p->dir < 0.0)
		p->dir += 2.0 * M_PI;
	while (p->dir >= 2.0 * M_PI)
		p->dir -= 2.0 * M_PI;
}

double	angles_add(double alpha, double beta)
{
	double	gamma;

	gamma = alpha + beta;
	while (gamma < 0.0)
		gamma += 2.0 * M_PI;
	while (gamma >= 2.0 * M_PI)
		gamma -= 2.0 * M_PI;
	return (gamma);
}
