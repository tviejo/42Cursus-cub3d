/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:22:50 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/25 14:44:00 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

void	free_parsing(t_cub3d *cub3d)
{
    free(cub3d->parsing.no);
    free(cub3d->parsing.so);
    free(cub3d->parsing.we);
    free(cub3d->parsing.ea);
    while (cub3d->parsing.map_height)
    {
        free(cub3d->parsing.map[cub3d->parsing.map_height - 1]);
        cub3d->parsing.map_height--;
    }
    free(cub3d->parsing.map);
}