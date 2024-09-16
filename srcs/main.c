/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:27:39 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/16 16:45:17 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//cub->game.last_tod = (struct timeval){.tv_sec = 0, .tv_usec = 0};

/* A appeler avant toute autre fonction d'initialisation
*/
void	init_game_vars(t_cub3d *cub)
{
	const int	mmap_rad = MINIMAP_RADIUS;

	cub->game.rendering_mode = RENDER_TEXTURE;
	cub->game.minimap_size = MINIMAP_SIZE;
	cub->game.minimap_radius = mmap_rad;
	cub->game.minimap_center = (t_point){{mmap_rad + 25}, {mmap_rad + 25}};
	cub->game.page = LANDING_PAGE;
	cub->game.m_speed = M_SPEED;
	cub->game.m_freeze = false;
	cub->game.time = 0.0;
	cub->game.frame_time = 0.01;
	cub->game.difficulty = 0;
	cub->monsters = NULL;
	cub->nb_monsters = 0;
	cub->nb_sprites = 0;
	cub->player.health = 100;
	cub->player.ammo = NB_AMMO;
	cub->player.vertical_fov = DEG_VERTICAL_FOV * M_PI / 180.0;
	cub->player.walk_distance = 0.0;
	cub->player.walk_height_shift = 0.0;
	cub->player.speed = 1.0;
	cub->player.shoot_last_time = 0.0;
	cub->map.wall_heightscale = 86.3 / DEG_VERTICAL_FOV;
}

/* A appeler juste avant l'appel à mlx_set_hooks_n_loop()
*/
void	init_game_final(t_cub3d *cub)
{
	cub->player.view_height = PLAYER_HEIGHT_FACTOR * cub->mlx.mlx_img.dim.height;
	srand(time(NULL));
	init_keys(cub);
	amlx_enable_win_resizing(&cub->mlx,
		(t_size2i){{480}, {360}}, (t_size2i){{9000}, {9000}});
	play_sound(SND_MUSIC, cub);
	play_sound(SND_WELCOME, cub);
	gettimeofday(&cub->game.last_tod, NULL);
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
or one argument: <map filename>\n"),
			0);
	map_fname = MAP_DEFAULT_FNAME;
	if (argc == 2)
		map_fname = argv[1];
	init_game_vars(&cub);
	mlx_init_data(&cub);
	if (mlx_start(&cub) == EXIT_FAILURE)
		ft_close(&cub, "mlx_start() fails !\n");
	if (parse_cub3d(map_fname, &cub) == EXIT_FAILURE)
		ft_close(&cub, "parse_cub3d() fails !\n");
	if (load_resources(&cub) == EXIT_FAILURE)
		ft_close(&cub, "load_resources() fails !\n");
	if (mlx_create_img(&cub, WINDOW_WIDTH, WINDOW_HEIGHT) == EXIT_FAILURE)
		ft_close(&cub, "mlx_create_img() fails !\n");
	init_game_final(&cub);
	mlx_set_hooks_n_loop(&cub);
	return (0);
}
