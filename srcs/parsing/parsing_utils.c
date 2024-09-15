/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:57:43 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/14 22:10:17 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ready_to_parse_map(t_cub3d *cub3d)
{
	if (cub3d->map.north_tfname == NULL || cub3d->map.south_tfname == NULL
		|| cub3d->map.west_tfname == NULL || cub3d->map.east_tfname == NULL)
		return (false);
	if (cub3d->map.col_ceil.b == -1 || cub3d->map.col_floor.b == -1)
		return (false);
	return (true);
}

bool	begin_with_tag(char *line, char *tag)
{
	const int	tag_len = ft_strlen(tag);

	while (line && *line == ' ')
		line++;
	return (line && ft_strncmp(line, tag, tag_len) == 0
		&& line[tag_len] == ' ');
}

/* En sortie, si value <> NULL :
 *     *value = pointeur sur valeur du tag ou NULL si tag non trouvé
 * renvoie true si tag trouvé, sinon false (idem begin_with_tag())
 */
bool	get_tag_value(char *line, char *tag, char **value)
{
	const int	tag_len = ft_strlen(tag);
	bool		tag_exists;

	while (line && *line == ' ')
		line++;
	tag_exists = line;
	tag_exists &= ft_strncmp(line, tag, tag_len) == 0;
	tag_exists &= line[tag_len] == ' ';
	if (value)
	{
		if (tag_exists)
			*value = line + tag_len + 1;
		else
			*value = NULL;
	}
	return (tag_exists);
}

static bool	text_parsed(char *line)
{
	static t_check_parse	check = {.north = false, .south = false,
		.west = false, .east = false, .floor = false, .ceil = false};

	if (begin_with_tag(line, MAP_TAG_NORTH_TEX))
		check.north = true;
	else if (begin_with_tag(line, MAP_TAG_SOUTH_TEX))
		check.south = true;
	else if (begin_with_tag(line, MAP_TAG_WEST_TEX))
		check.west = true;
	else if (begin_with_tag(line, MAP_TAG_EAST_TEX))
		check.east = true;
	else if (line[0] == 'F')
		check.floor = true;
	else if (line[0] == 'C')
		check.ceil = true;
	if (check.north && check.south && check.west && check.east && check.floor
		&& check.ceil)
		return (true);
	return (false);
}

int	find_map_size(int fd, t_cub3d *cub3d)
{
	char		*line;
	static int	i = 0;

	line = get_next_line(fd);
	while (line && !is_map(line) && text_parsed(line) == false)
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line && !is_map(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line && is_map(line) && i++ <= INT_MAX)
	{
		if ((int)ft_strlen(line) > cub3d->map.width)
			cub3d->map.width = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	cub3d->map.height = i;
	return (EXIT_SUCCESS);
}
