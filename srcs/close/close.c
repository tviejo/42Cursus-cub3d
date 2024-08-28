/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:01:14 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/28 15:53:17 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_close(t_cub3d *cub3d)
{
	free_parsing(cub3d);
	mlx_close(cub3d);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
