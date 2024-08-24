/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:08:35 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/24 22:52:54 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

void	init_parsing(t_cub3d *cub3d)
{
    cub3d->map_height = 0;
    cub3d->no = NULL;
    cub3d->so = NULL;
    cub3d->we = NULL;
    cub3d->ea = NULL;
    cub3d->floor.r = -1;
    cub3d->floor.g = -1;
    cub3d->floor.b = -1;
    cub3d->ceiling.r = -1;
    cub3d->ceiling.g = -1;
    cub3d->ceiling.b = -1;
    cub3d->map = NULL;
}