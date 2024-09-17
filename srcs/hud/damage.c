/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:28:27 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/17 12:04:27 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static inline int	get_shade(int color, double shade)
{
	return (
		(color & 0xff0000)
		+ ((int)(((color >> 8) & 255) * shade) << 8)
		+ (int)((color & 255) * shade));
}

void    shade_image (t_image *img, int health)
{
	double	shade;
	int		x;
	int		y;

	if (health >= 55)
		return ;
	shade = health * (0.7 / 55.0) + 0.3;
	y = 0;
	while (y < img->dim.height)
	{
		x = 0;
		while (x < img->dim.width)
		{
			*(int *)(img->pixels + y * img->line_size + 4 * x) = get_shade(
				*(int *)(img->pixels + y * img->line_size + 4 * x), shade);
			x++;
		}
		y++;
	}
}
