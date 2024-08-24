/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:29:44 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/24 22:52:11 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "parsing.h"

typedef struct	s_color
{
    int		r;
    int		g;
    int		b;
}				t_color;

typedef struct	s_cub3d
{
    char        **map;
    size_t         map_height;
    char		*no;
    char		*so;
    char		*we;
    char		*ea;
    t_color        floor;
    t_color        ceiling;
}				t_cub3d;

int		parse_cub(char *file, t_cub3d *cub3d);
bool    is_map(char *line);
int     parse_map(char *line, int fd, t_cub3d *cub3d);
int    find_map_size(int fd, t_cub3d *cub3d);
void    parse_texture(char *line, t_cub3d *cub3d);
void    parse_color(char *line, t_cub3d *cub3d);
void    init_parsing(t_cub3d *cub3d);
void    free_parsing(t_cub3d *cub3d);
void    print_parsing(t_cub3d *cub3d);
bool    is_texture(char *line);
bool    is_color(char *line);

#endif
