/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:22:50 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/26 15:05:23 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

void	free_parsing(t_cub3d *cub3d)
{
    size_t i;

    i = 0;
    if (cub3d->parsing.no)
        free(cub3d->parsing.no);
    if (cub3d->parsing.so)
        free(cub3d->parsing.so);
    if (cub3d->parsing.we)
        free(cub3d->parsing.we);
    if (cub3d->parsing.ea)
        free(cub3d->parsing.ea);
    while (i < cub3d->parsing.map_height + 2)
    {
        free(cub3d->parsing.map[i]);
        i++;
    }
    free(cub3d->parsing.map);
}