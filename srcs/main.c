/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:27:39 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/25 15:06:02 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
	t_cub3d cub3d;

	if (argc != 2)
		return (0);
	if (parse_cub(argv[1], &cub3d) == EXIT_FAILURE)
		return (0);
	if (mlx_start(&cub3d) == EXIT_FAILURE)
		return (0);
	if (mlx_create_img(&cub3d) == EXIT_FAILURE)
		return (0);
	mlx_looping(&cub3d);
	return (0);
}
