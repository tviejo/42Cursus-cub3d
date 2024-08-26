/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:08:35 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/26 15:44:33 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

void	init_parsing(t_cub3d *cub3d)
{
    cub3d->parsing.map_height = 0;
    cub3d->parsing.map_with = 0;
    cub3d->parsing.no = NULL;
    cub3d->parsing.so = NULL;
    cub3d->parsing.we = NULL;
    cub3d->parsing.ea = NULL;
    cub3d->parsing.floor.r = -1;
    cub3d->parsing.floor.g = -1;
    cub3d->parsing.floor.b = -1;
    cub3d->parsing.cei.r = -1;
    cub3d->parsing.cei.g = -1;
    cub3d->parsing.cei.b = -1;
    cub3d->parsing.map = NULL;
    cub3d->player.x = -1;
    cub3d->player.y = -1;
}
