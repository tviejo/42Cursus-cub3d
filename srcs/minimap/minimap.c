/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:07:14 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/26 16:57:03 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include  "../../includes/cub3d.h"

static void print_player(t_cub3d *cub3d)
{
    size_t x;
    size_t y;

    x = 0;
    while (x < 10)
    {
        y = 0;
        while (y < 10)
        {
            img_pix_put(cub3d, cub3d->player.y * 10 + x, cub3d->player.x * 10 + y, 0xFF0000);
            y++;
        }
        x++;
    }
}
static int print_square(size_t i, size_t j, t_cub3d *cub3d, int color)
{
    size_t x;
    size_t y;

    x = 0;
    while (x < 10)
    {
        y = 0;
        while (y < 10)
        {
            img_pix_put(cub3d, j * 10 + x, i * 10 + y, color);
            y++;
        }
        x++;
    }
    return (EXIT_SUCCESS);
}

int minimap(t_cub3d *cub3d)
{
    size_t i;
    size_t j;

    i = 0;
    while (i < cub3d->parsing.map_height + 1)
    {
        j = 0;
        while (j < cub3d->parsing.map_with )
        {
            if (cub3d->parsing.map[i][j] == '1')
                print_square(i, j, cub3d, 0x0000FF);
            else if (cub3d->parsing.map[i][j] == '0')
                print_square(i, j, cub3d, 0xFFFFFF);
            j++;
        }
        i++;
    }
    print_player(cub3d);
    return (EXIT_SUCCESS);
}