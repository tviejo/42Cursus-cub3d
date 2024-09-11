/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:27:39 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/11 16:00:57 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	init_game(t_cub3d *cub)
{
	cub->game.rendering_mode = RENDER_TEXTURE;
	cub->game.minimap_size = 20;
	cub->game.minimap_center = (t_point){{130}, {130}};
	cub->game.page = LANDING_PAGE;
	cub->game.m_speed = M_SPEED;
	cub->game.last_time = (struct timeval){.tv_sec = 0, .tv_usec = 0};
	cub->game.dificulty = 0;
	cub->monsters = NULL;
	cub->nb_monsters = 0;
	cub->player.health = 100;
	cub->player.ammo = 10; 
	cub->player.vertical_fov = DEG_VERTICAL_FOV * M_PI / 180.0;
	cub->player.view_height = 0.08 * cub->mlx.mlx_img.dim.height;
	cub->player.walk_distance = 0.0;
	cub->player.walk_height_shift = 0.0;
	cub->player.speed = 1.0;
	cub->map.wall_heightscale = 86.3 / DEG_VERTICAL_FOV;
	mlx_init_data(cub);
}

int	load_resources(t_cub3d *c)
{
	if (load_hud_textures(c) == EXIT_FAILURE)
		return (ft_dprintf(2, "load_hud_textures() fails !\n"), EXIT_FAILURE);
	if (load_sprites(c) == EXIT_FAILURE)
		return (ft_dprintf(2, "load_sprites() fails !\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub;
	char	*map_fname;

	if (argc > 2)
		return (ft_dprintf(2, "Error: please, provide zero (for default map) \
or one argument: <map filename>\n"), 0);
	map_fname = MAP_DEFAULT_FNAME;
	if (argc == 2)
		map_fname = argv[1];
	init_game(&cub);
	if (mlx_start(&cub) == EXIT_FAILURE)
		ft_close(&cub, "mlx_start() fails !\n");
	if (parse_cub3d(map_fname, &cub) == EXIT_FAILURE)
		ft_close(&cub, "parse_cub3d() fails !\n");
	if (load_resources(&cub) == EXIT_FAILURE)
		ft_close(&cub, "load_resources() fails !\n");
	if (mlx_create_img(&cub) == EXIT_FAILURE)
		ft_close(&cub, "mlx_create_img() fails !\n");
	init_keys(&cub);
	gettimeofday(&cub.game.last_time, NULL);
	play_sound(SND_MUSIC, &cub);
	play_sound(SND_WELCOME, &cub);
	mlx_looping(&cub);
	return (0);
}
