/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:01:14 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/08 17:12:28 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close_cr(t_cub3d *cub3d)
{
	ft_close(cub3d, NULL);
	return (EXIT_SUCCESS);
}

int	ft_close(t_cub3d *cub3d, char *errmsg)
{
	kill_sound();
	if (errmsg)
		ft_dprintf(2, errmsg);
	clear_monsters(cub3d);
	free_parsing(&cub3d->map);
	mlx_close(&cub3d->mlx);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
