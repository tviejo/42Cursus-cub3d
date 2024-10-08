/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:01:14 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/18 13:09:58 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	on_win_close(t_cub3d *cub)
{
	ft_close(cub, NULL);
	return (EXIT_SUCCESS);
}

int	ft_close(t_cub3d *cub, char *errmsg)
{
	kill_sound();
	if (errmsg)
		ft_dprintf(2, errmsg);
	clear_monsters(cub);
	free_parsing(&cub->map);
	free_sprites(cub);
	mlx_close(&cub->mlx);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
