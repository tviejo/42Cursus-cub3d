/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:57:05 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/25 14:44:00 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

bool    is_texture(char *line)
{
    int		i;

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

static char	*get_texture(char *line)
{
    int		i;
    char	*texture;

    i = 2;
    while (line[i] == ' ')
        i++;
    texture = ft_strdup(&line[i]);
    return (texture);
}

void    parse_texture(char *line, t_cub3d *cub3d)
{
    if (ft_strncmp(line, "NO", 2) == 0)
        cub3d->parsing.no = get_texture(line);
    if (ft_strncmp(line, "SO", 2) == 0)
        cub3d->parsing.so = get_texture(line);
    if (ft_strncmp(line, "WE", 2) == 0)
        cub3d->parsing.we = get_texture(line);
    if (ft_strncmp(line, "EA", 2) == 0)
        cub3d->parsing.ea = get_texture(line);
    free(line);
}
