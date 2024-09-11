/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:57:05 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/11 01:40:19 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	errmsg(char *msg, char *fname)
{
	ft_dprintf(2, "Error: %s [%s]\n", msg, fname);
	perror(NULL);
}

static int	load_tex(void *mlx_ptr, char *tagval,
						t_image *img, char **filename)
{
	if (img->ptr)
		return (errmsg("load_texture(): already loaded (check the map file !)",
				tagval), EXIT_FAILURE);
	*filename = ft_strtrim(tagval, " \n");
	if (*filename == NULL)
		return (errmsg("load_texture(): ft_strtrim()", tagval),
			EXIT_FAILURE);
	img->ptr = mlx_xpm_file_to_image(mlx_ptr, *filename,
			&img->dim.width, &img->dim.height);
	if (img->ptr == NULL)
		return (errmsg("load_texture(): mlx_xpm_file_to_image()", *filename),
			EXIT_FAILURE);
	img->pixels = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_size,
			&img->endian);
	if (img->pixels == NULL)
		return (errmsg("load_texture(): mlx_get_data_addr()", *filename),
			EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


int	parse_texture(char *line, t_cub3d *c)
{
	int		retval;
	char	*tagval;

	retval = EXIT_FAILURE;
	if (get_tag_value(line, MAP_TAG_NORTH_TEX, &tagval))
		retval = load_tex(c->mlx.mlx_ptr, tagval,
				&c->mlx.wall_tex[North], &c->map.north_tfname);
	if (get_tag_value(line, MAP_TAG_SOUTH_TEX, &tagval))
		retval = load_tex(c->mlx.mlx_ptr, tagval,
				&c->mlx.wall_tex[South], &c->map.south_tfname);
	if (get_tag_value(line, MAP_TAG_WEST_TEX, &tagval))
		retval = load_tex(c->mlx.mlx_ptr, tagval,
				&c->mlx.wall_tex[West], &c->map.west_tfname);
	if (get_tag_value(line, MAP_TAG_EAST_TEX, &tagval))
		retval = load_tex(c->mlx.mlx_ptr, tagval,
				&c->mlx.wall_tex[East], &c->map.east_tfname);
	if (get_tag_value(line, MAP_TAG_OPEN_DOOR_TEX, &tagval))
		retval = load_tex(c->mlx.mlx_ptr, tagval,
				&c->mlx.open_door_tex, &c->map.open_door_tfname);
	if (get_tag_value(line, MAP_TAG_CLOSED_DOOR_TEX, &tagval))
		retval = load_tex(c->mlx.mlx_ptr, tagval,
				&c->mlx.closed_door_tex, &c->map.closed_door_tfname);
	free(line);
	return (retval);
}
