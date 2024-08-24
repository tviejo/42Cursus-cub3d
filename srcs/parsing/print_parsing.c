/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:22:05 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/24 22:55:37 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

void	print_parsing(t_cub3d *cub3d)
{
    size_t i;

    i = 0;
    printf("no: %s\n", cub3d->no);
    printf("so: %s\n", cub3d->so);
    printf("we: %s\n", cub3d->we);
    printf("ea: %s\n", cub3d->ea);
    printf("floor: %d, %d, %d\n", cub3d->floor.r, cub3d->floor.g, cub3d->floor.b);
    printf("ceiling: %d, %d, %d\n\n\n", cub3d->ceiling.r, cub3d->ceiling.g, cub3d->ceiling.b);
    while (i < cub3d->map_height)
    {
        printf("%s\n", cub3d->map[i]);
        i++;
    }
}