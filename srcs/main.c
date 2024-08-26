/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:27:39 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/26 15:46:57 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int init(t_cub3d *cub3d)
{
	init_keys(cub3d);
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	t_cub3d cub3d;

	if (argc != 2)
		return (0);
	if (parse_cub(argv[1], &cub3d) == EXIT_FAILURE)
		return (0);
	print_parsing(&cub3d);
	if (mlx_start(&cub3d) == EXIT_FAILURE)
		return (0);
	if (mlx_create_img(&cub3d) == EXIT_FAILURE)
		return (0);
	init(&cub3d);
	mlx_looping(&cub3d);
	return (0);
}
