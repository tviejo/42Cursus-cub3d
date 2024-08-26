/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:20:11 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/26 19:15:13 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

static int open_door(t_cub3d *cub3d, int i, int j)
{
    cub3d->parsing.map[i][j] = 'O';
    return (0);
}
static bool wall(t_cub3d *cub3d)
{
    if (cub3d->parsing.map[(int)cub3d->player.x][(int)cub3d->player.y] == '1' || cub3d->parsing.map[(int)cub3d->player.x][(int)cub3d->player.y] == 'C')
    {
        if (cub3d->parsing.map[(int)cub3d->player.x][(int)cub3d->player.y] == 'C' && cub3d->keys.open)
            open_door(cub3d, cub3d->player.x, cub3d->player.y);
        else
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
    // int x;
    // int y;

    // mlx_mouse_get_pos(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, &x, &y);
    // if (y - cub3d->keys.mouse_y < 10)
    //     cub3d->player.dir -= (y - cub3d->keys.mouse_y) * 0.1;
    // cub3d->keys.mouse_x = x;
    // cub3d->keys.mouse_y = y;
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