/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:59:05 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/24 22:39:34 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

bool        is_map(char *line)
{
    int		i;

    i = 0;
    while (line && line[i] == ' ')
        i++;
    if (line && (line[i] == '1' || line[i] == '0'))
        return (true);
    return (false);
}
int        find_map_size(int fd, t_cub3d *cub3d)
{
    char	*line;
    size_t    i;

    i = 0;
    line = get_next_line(fd);
    while (line && is_map(line) != true)
    {
        free(line);
        line = get_next_line(fd);
    }
    while (line && is_map(line) == true)
    {
        i++;
        free(line);
        line = get_next_line(fd);
    }
    if (line)
        free(line);
    cub3d->map_height = i;
    return (EXIT_SUCCESS);
}


int        parse_map(char *line, int fd, t_cub3d *cub3d)
{
    size_t		i;
    static bool    map = false;

    if (map == true)
        return (EXIT_FAILURE);
    map = true;
    ft_dprintf(1, "Parsing map\n");
    cub3d->map = malloc(sizeof(char *) * (cub3d->map_height + 1));
    if (!cub3d->map)
        return (EXIT_FAILURE);
    i = 0;
    while (i < cub3d->map_height)
    {
        cub3d->map[i] = ft_strdup(line);
        free(line);
        if (!cub3d->map[i])
            return (EXIT_FAILURE);
        line = get_next_line(fd);
        i++;
    }
    free(line);
    return (EXIT_SUCCESS);
}