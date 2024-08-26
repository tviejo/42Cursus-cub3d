/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:22:05 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/26 15:36:08 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

void	print_parsing(t_cub3d *cub3d)
{
    size_t i;

    i = 0;
    printf("no: %s\n", cub3d->parsing.no);
    printf("so: %s\n", cub3d->parsing.so);
    printf("we: %s\n", cub3d->parsing.we);
    printf("ea: %s\n", cub3d->parsing.ea);
    printf("floor: %d, %d, %d\n", cub3d->parsing.floor.r, cub3d->parsing.floor.g, cub3d->parsing.floor.b);
    printf("ce: %d, %d, %d\n\n\n", cub3d->parsing.cei.r, cub3d->parsing.cei.g, cub3d->parsing.cei.b);
    while (i < cub3d->parsing.map_height + 2)
    {
        printf("%s\n", cub3d->parsing.map[i]);
        i++;
    }

    printf("player: %f, %f\n", cub3d->player.x, cub3d->player.y);
}