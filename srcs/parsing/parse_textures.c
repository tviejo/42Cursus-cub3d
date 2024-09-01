/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:57:05 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/31 23:57:45 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_texture(char *line)
{
	while (line && *line == ' ')
		line++;
	return (begin_with_tag(line, MAP_TAG_NORTH_TEXTURE)
		|| begin_with_tag(line, MAP_TAG_SOUTH_TEXTURE)
		|| begin_with_tag(line, MAP_TAG_WEST_TEXTURE)
		|| begin_with_tag(line, MAP_TAG_EAST_TEXTURE)
	);
}

static void	errmsg(char *msg, char *fname)
{
	ft_dprintf(2, "Error: %s [%s]\n", msg, fname);
	perror(NULL);
}

static int	load_texture(void *mlx_ptr, char *tagval,
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
	if (get_tag_value(line, MAP_TAG_NORTH_TEXTURE, &tagval))
		retval = load_texture(c->mlx.mlx_ptr, tagval,
				&c->mlx.text_north, &c->map.north_tfname);
	if (get_tag_value(line, MAP_TAG_SOUTH_TEXTURE, &tagval))
		retval = load_texture(c->mlx.mlx_ptr, tagval,
				&c->mlx.text_south, &c->map.south_tfname);
	if (get_tag_value(line, MAP_TAG_WEST_TEXTURE, &tagval))
		retval = load_texture(c->mlx.mlx_ptr, tagval,
				&c->mlx.text_west, &c->map.west_tfname);
	if (get_tag_value(line, MAP_TAG_EAST_TEXTURE, &tagval))
		retval = load_texture(c->mlx.mlx_ptr, tagval,
				&c->mlx.text_east, &c->map.east_tfname);
	free(line);
	return (retval);
}
