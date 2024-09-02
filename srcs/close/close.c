/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:01:14 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/01 11:55:43 by ade-sarr         ###   ########.fr       */
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
