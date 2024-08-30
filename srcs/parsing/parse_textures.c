/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:57:05 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/30 14:43:37 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_texture(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] == ' ')
		i++;
	if (line && ft_strncmp(&line[i], "NO", 2) == 0)
		return (true);
	if (line && ft_strncmp(&line[i], "SO", 2) == 0)
		return (true);
	if (line && ft_strncmp(&line[i], "WE", 2) == 0)
		return (true);
	if (line && ft_strncmp(&line[i], "EA", 2) == 0)
		return (true);
	return (false);
}

static void	errmsg(char *msg, char *fname)
{
	ft_dprintf(2, "Error: %s [%s]\n", msg, fname);
	perror(NULL);
}

static int	load_texture(void *mlx_ptr, char *line, t_image *img, char **fname)
{
	*fname = ft_strtrim(&line[2], " \n");
	if (*fname == NULL)
		return (free(line), errmsg(
				"load_texture(): ft_strtrim()", &line[2]), EXIT_FAILURE);
	img->ptr = mlx_xpm_file_to_image(mlx_ptr, *fname,
			&img->dim.width, &img->dim.height);
	if (img->ptr == NULL)
		return (free(line), errmsg(
				"load_texture(): mlx_xpm_file_to_image", *fname), EXIT_FAILURE);
	img->pixels = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_size,
			&img->endian);
	if (img->pixels == NULL)
		return (free(line), errmsg(
				"load_texture(): mlx_get_data_addr()", *fname), EXIT_FAILURE);
	free(line);
	return (EXIT_SUCCESS);
}

int	parse_texture(char *line, t_cub3d *c)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (load_texture(c->mlx.mlx_ptr, line,
				&c->mlx.text_north, &c->map.north_tfname));
	if (ft_strncmp(line, "SO", 2) == 0)
		return (load_texture(c->mlx.mlx_ptr, line,
				&c->mlx.text_south, &c->map.south_tfname));
	if (ft_strncmp(line, "WE", 2) == 0)
		return (load_texture(c->mlx.mlx_ptr, line,
				&c->mlx.text_west, &c->map.west_tfname));
	if (ft_strncmp(line, "EA", 2) == 0)
		return (load_texture(c->mlx.mlx_ptr, line,
				&c->mlx.text_east, &c->map.east_tfname));
	free(line);
	return (EXIT_FAILURE);
}
