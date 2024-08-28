/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:56:34 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/28 15:04:05 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	is_valid_rgb(int r, int g, int b)
{
	if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
		return (true);
	return (false);
}

bool	is_color(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] == ' ')
		i++;
	if (line && (line[i] == 'F' || line[i] == 'C'))
		return (true);
	return (false);
}

static int	assign_color(int r, int g, int b, t_color *color)
{
	color->r = r;
	color->g = g;
	color->b = b;
	return (EXIT_SUCCESS);
}

static int	find_type(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] == ' ')
		i++;
	if (line && line[i] == 'F')
		return (FLOOR);
	return (ce);
}

void	parse_color(char *line, t_cub3d *cube3d)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 1;
	while (line[i] == ' ')
		i++;
	r = ft_atoi(&line[i - 1]);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	g = ft_atoi(&line[i + 1]);
	while (line[i + 1] && ft_isdigit(line[i + 1]))
		i++;
	b = ft_atoi(&line[i + 1]);
	if (is_valid_rgb(r, g, b) == false)
		return ;
	if ((find_type(line)) == FLOOR)
		assign_color(r, g, b, &cube3d->map.col_floor);
	else
		assign_color(r, g, b, &cube3d->map.col_ceil);
	free(line);
}
