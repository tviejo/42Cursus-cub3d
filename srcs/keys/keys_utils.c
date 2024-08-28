/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:24:17 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/28 01:09:17 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_keys(t_cub3d *cub3d)
{
	ft_memset(&cub3d->inputs, 0, sizeof(t_player_inputs));
	return (0);
}
