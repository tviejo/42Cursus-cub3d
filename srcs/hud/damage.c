/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:28:27 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/16 19:56:35 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static inline int	shade(int color, int health)
{
    double    shade;

    shade = health / 100.0 + 0.5;
    if (shade > 1.0)
    {
        return (color);
    }
	return (
		((int)(((color >> 16) & 255) * 1) << 16)
		+ ((int)(((color >> 8) & 255) * shade) << 8)
		+ (int)((color & 255) * shade));
}

void    shade_image (t_image *img, int health)
{
    int x;
    int y;

    if (health > 100)
    {
        return ;
    }
    y = 0;
    while (y < img->dim.height)
    {
        x = 0;
        while (x < img->dim.width)
        {
            (void)health;
            *(int *)(img->pixels + y * img->line_size + 4 * x) = shade(*(int *)(img->pixels + y * img->line_size + 4 * x), health);
            x++;
        }
        y++;
    }
}

