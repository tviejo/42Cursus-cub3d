/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:22:50 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/24 22:23:07 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

void	free_parsing(t_cub3d *cub3d)
{
    free(cub3d->no);
    free(cub3d->so);
    free(cub3d->we);
    free(cub3d->ea);
    while (cub3d->map_height)
    {
        free(cub3d->map[cub3d->map_height - 1]);
        cub3d->map_height--;
    }
    free(cub3d->map);
}