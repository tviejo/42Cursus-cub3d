/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:01:14 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/05 13:52:29 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(t_cub3d *cub3d, char *errmsg)
{
	if (errmsg)
		ft_dprintf(2, errmsg);
	free_parsing(&cub3d->map);
	mlx_close(&cub3d->mlx);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
