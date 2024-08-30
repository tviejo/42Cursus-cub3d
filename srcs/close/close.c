/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:01:14 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/30 14:00:00 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(t_cub3d *cub3d)
{
	free_parsing(&cub3d->map);
	mlx_close(&cub3d->mlx);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
