/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:20:11 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/26 16:58:47 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

static bool wall(t_cub3d *cub3d)
{
    if (cub3d->parsing.map[(int)cub3d->player.x][(int)cub3d->player.y] == '1')
    {
        return (true); 
    }
    if (cub3d->parsing.map[(int)cub3d->player.x + 1][(int)cub3d->player.y + 1] == '1')
    {
        return (true);
    }
    return (false);
}

static void translation(t_cub3d *cub3d)
{
    if (cub3d->keys.up)
    {
        cub3d->player.x -= cos(cub3d->player.dir) * TRANS_SPEED;
        cub3d->player.y -= sin(cub3d->player.dir) * TRANS_SPEED;
    }
    if (cub3d->keys.down)
    {
        cub3d->player.x += cos(cub3d->player.dir) * TRANS_SPEED;
        cub3d->player.y += sin(cub3d->player.dir) * TRANS_SPEED;
    }
    if (cub3d->keys.left)
    {
        cub3d->player.x += cos(cub3d->player.dir - M_PI_2) * TRANS_SPEED;
        cub3d->player.y += sin(cub3d->player.dir - M_PI_2) * TRANS_SPEED;
    }
    if (cub3d->keys.right)
    {
        cub3d->player.x += cos(cub3d->player.dir + M_PI_2) * TRANS_SPEED;
        cub3d->player.y += sin(cub3d->player.dir + M_PI_2) * TRANS_SPEED;
    }
}

static void rotation(t_cub3d *cub3d)
{
    if (cub3d->keys.turn_left)
        cub3d->player.dir += ROT_SPEED;
    if (cub3d->keys.turn_right)
        cub3d->player.dir -= ROT_SPEED;
}

int update_player_pos(t_cub3d *cub3d)
{
    double old_pos_x;
    double old_pos_y;

    old_pos_x = cub3d->player.x;
    old_pos_y = cub3d->player.y;
    rotation(cub3d);
    translation(cub3d);
    if (wall(cub3d))
    {
        cub3d->player.x = old_pos_x;
        cub3d->player.y = old_pos_y;
    }
    return (0);
}