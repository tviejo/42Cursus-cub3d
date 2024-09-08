/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:27:39 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/08 13:56:53 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init(t_cub3d *cub3d)
{
	init_keys(cub3d);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;
	char	*map_fname;

	if (argc > 2)
		return (ft_dprintf(2, "Error: please, provide zero (for default map) \
or one argument: <map filename>\n"), 0);
	map_fname = MAP_DEFAULT_FNAME;
	if (argc == 2)
		map_fname = argv[1];
	mlx_init_data(&cub3d);
	if (mlx_start(&cub3d) == EXIT_FAILURE)
		ft_close(&cub3d, "mlx_start() fails !\n");
	if (parse_cub3d(map_fname, &cub3d) == EXIT_FAILURE)
		ft_close(&cub3d, "parse_cub3d() fails !\n");
	play_sound(MUSIC);
	if (mlx_create_img(&cub3d) == EXIT_FAILURE)
		ft_close(&cub3d, "mlx_create_img() fails !");
	init(&cub3d);
	mlx_looping(&cub3d);
	return (0);
}
