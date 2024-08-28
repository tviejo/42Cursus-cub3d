/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:22:50 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/28 15:02:24 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_parsing(t_cub3d *cub3d)
{
	size_t	i;

	i = 0;
	if (cub3d->map.no)
		free(cub3d->map.no);
	if (cub3d->map.so)
		free(cub3d->map.so);
	if (cub3d->map.we)
		free(cub3d->map.we);
	if (cub3d->map.ea)
		free(cub3d->map.ea);
	while (i < cub3d->map.height + 2)
	{
		free(cub3d->map.m[i]);
		i++;
	}
	free(cub3d->map.m);
}
