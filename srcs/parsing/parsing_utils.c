/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:57:43 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/01 04:28:22 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	begin_with_tag(char *line, char *tag)
{
	const int	tag_len = ft_strlen(tag);

	while (line && *line == ' ')
		line++;
	return (
		line
		&& ft_strncmp(line, tag, tag_len) == 0
		&& line[tag_len] == ' '
	);
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
	tag_exists = line
		&& ft_strncmp(line, tag, tag_len) == 0
		&& line[tag_len] == ' ';
	if (value)
	{
		if (tag_exists)
			*value = line + tag_len + 1;
		else
			*value = NULL;
	}
	return (tag_exists);
}

bool	is_map(char *line)
{
	while (line && *line == ' ')
		line++;
	return (line && (*line == '1' || *line == '0'));
}

int	find_map_size(int fd, t_cub3d *cub3d)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line && !is_map(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line && is_map(line))
	{
		i++;
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
