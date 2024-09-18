/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:56:34 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/18 13:56:56 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_valid_color(t_color c)
{
	return (c.r >= 0 && c.r <= 255 && c.g >= 0 && c.g <= 255 && c.b >= 0
		&& c.b <= 255);
}

bool	is_color(char *line, t_cub3d *cub)
{
	return ((begin_with_tag(line, MAP_TAG_FLOOR_COLOR)
			&& cub->map.col_floor.r == -1) || (begin_with_tag(line,
				MAP_TAG_CEIL_COLOR) && cub->map.col_ceil.r == -1));
}

/*static int	find_type(char *line)
{
	if (begin_with_tag(line, MAP_TAG_FLOOR_COLOR))
		return (FLOOR);
	return (CEIL);
}*/
static void	assign_color(t_cub3d *cube3d, int colortype, t_color color)
{
	if (colortype == CT_FLOOR)
	{
		cube3d->map.col_floor = color;
		cube3d->mlx.color_floor = (color.r << 16) + (color.g << 8) + color.b;
	}
	else
	{
		cube3d->map.col_ceil = color;
		cube3d->mlx.color_ceil = (color.r << 16) + (color.g << 8) + color.b;
	}
}

bool	parse_color(char *line, t_cub3d *cube3d)
{
	t_color	color;
	int		colortype;
	char	*vals;

	colortype = CT_CEIL;
	if (!get_tag_value(line, MAP_TAG_CEIL_COLOR, &vals))
	{
		colortype = CT_FLOOR;
		get_tag_value(line, MAP_TAG_FLOOR_COLOR, &vals);
	}
	color.r = ft_atoi(vals);
	while (*vals && (ft_isdigit(*vals) || *vals == ' '))
		vals++;
	color.g = ft_atoi(++vals);
	while (*vals && (ft_isdigit(*vals) || *vals == ' '))
		vals++;
	color.b = ft_atoi(++vals);
	if (is_valid_color(color))
		assign_color(cube3d, colortype, color);
	else
		return (ft_dprintf(2, "bad color\n"), false);
	free(line);
	return (true);
}
