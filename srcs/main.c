/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:27:39 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/30 14:11:58 by ade-sarr         ###   ########.fr       */
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
	map_fname = DEFAULT_MAP_FNAME;
	if (argc == 2)
		map_fname = argv[1];
	mlx_init_data(&cub3d);
	if (mlx_start(&cub3d) == EXIT_FAILURE)
		ft_close(&cub3d);
	if (parse_cub3d(map_fname, &cub3d) == EXIT_FAILURE)
		ft_close(&cub3d);
	print_parsing(&cub3d);
	if (mlx_create_img(&cub3d) == EXIT_FAILURE)
		ft_close(&cub3d);
	init(&cub3d);
	mlx_looping(&cub3d);
	return (0);
}
