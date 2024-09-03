/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:26:41 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/03 15:15:29 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static t_door_state door_present(t_cub3d *cub, t_pointd pos)
{
    const int x = (int)pos.x;
    const int y = (int)pos.y;
    int i;
    int j;

    i = -1;
    while (i < 2)
    {
        j = -1;
        while (j < 2)
        {   
            if (cub->map.m[y + i][x + j] == 'C' && (i != 0 || j != 0))
                return (DOOR_CLOSED);
            if (cub->map.m[y + i][x + j] == 'O' && (i != 0 || j != 0))
                return (DOOR_OPENED);
            j++;
        }
        i++;
    }
    return (NO_DOOR);
}
static int moove_door(t_cub3d *cub, t_pointd pos)
{
    const int x = (int)pos.x;
    const int y = (int)pos.y;
    int i;
    int j;

    i = -1;
    while (i < 2)
    {
        j = -1;
        while (j < 2)
        {
            if (cub->map.m[y + i][x + j] == 'C')
                return ( cub->map.m[y + i][x + j] = 'O', 0);
            if (cub->map.m[y + i][x + j] == 'O')
                return ( cub->map.m[y + i][x + j] = 'C', 0);
            j++;
        }
        i++;
    }
    return (EXIT_FAILURE);
}

int    interact_door(t_cub3d *cub, t_pointd pos)
{
    static struct timeval	last_open = {0, 0};
    struct timeval	current_time;

    ft_dprintf(2, "%d\n", door_present(cub, pos));
    if (cub->inputs.open && door_present(cub, pos) != NO_DOOR)
    {
        gettimeofday(&current_time, NULL);
        ft_dprintf(2, "Door interaction\n");
        if ((int)current_time.tv_sec - (int)last_open.tv_sec > 1)
        {
            ft_dprintf(2, "Moove door\n");
            moove_door(cub, pos);
            last_open = current_time;
        }
        return (EXIT_SUCCESS);
    }
    return (EXIT_FAILURE);
}