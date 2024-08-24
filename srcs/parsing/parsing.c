/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:57:43 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/24 22:42:06 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

int		parse_cub(char *file, t_cub3d *cub3d)
{
    int		fd;
    char	*line;

    init_parsing(cub3d);
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (EXIT_FAILURE);
    find_map_size(fd, cub3d);
    close(fd);
    fd = open(file, O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        if (is_map(line) == true)
            parse_map(line, fd, cub3d);
        else if (is_texture(line) == true)
            parse_texture(line, cub3d);
        else if (is_color(line) == true)
            parse_color(line, cub3d);
        else
            free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    return (EXIT_SUCCESS);
}
