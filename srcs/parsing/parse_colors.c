/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:56:34 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/30 15:53:41 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_valid_color(t_color c)
{
	return (c.r >= 0 && c.r <= 255
		&& c.g >= 0 && c.g <= 255
		&& c.b >= 0 && c.b <= 255);
}

bool	is_color(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] == ' ')
		i++;
	return (line && (line[i] == 'F' || line[i] == 'C'));
}

static int	find_type(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] == ' ')
		i++;
	if (line && line[i] == 'F')
		return (FLOOR);
	return (CEIL);
}

static void	assign_color(t_cub3d *cube3d, char *line, t_color color)
{
	if ((find_type(line)) == FLOOR)
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

void	parse_color(char *line, t_cub3d *cube3d)
{
	int		i;
	t_color	c;

	i = 1;
	while (line[i] == ' ')
		i++;
	c.r = ft_atoi(&line[i - 1]);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	c.g = ft_atoi(&line[i + 1]);
	while (line[i + 1] && ft_isdigit(line[i + 1]))
		i++;
	c.b = ft_atoi(&line[i + 1]);
	if (is_valid_color(c))
		assign_color(cube3d, line, c);
	free(line);
}
