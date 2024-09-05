/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:52:52 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/05 13:27:31 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    mouse_move(int button, int x, int y, t_cub3d *cub3d)
{
    (void)button;
    cub3d->inputs.mouse_x = x;
    cub3d->inputs.mouse_y = y;
    return (EXIT_SUCCESS);
}