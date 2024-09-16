/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:00:46 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/16 09:38:20 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_texture(char *line)
{
	while (line && *line == ' ')
		line++;
	return (begin_with_tag(line, MAP_TAG_NORTH_TEX)
		|| begin_with_tag(line, MAP_TAG_SOUTH_TEX)
		|| begin_with_tag(line, MAP_TAG_WEST_TEX)
		|| begin_with_tag(line, MAP_TAG_EAST_TEX)
		|| begin_with_tag(line, MAP_TAG_OPEN_DOOR_TEX)
		|| begin_with_tag(line, MAP_TAG_CLOSED_DOOR_TEX)
		|| begin_with_tag(line, MAP_TAG_CEIL_TEX)
		|| begin_with_tag(line, MAP_TAG_FLOOR_TEX)
	);
}

static bool	is_valid(int c)
{
	if (c == '0' || c == '1' || c == ' ')
		return (true);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	if (c == 'C' || c == 'O')
		return (true);
	if (c == 'A')
		return (true);
	return (false);
}

static void	parse_player(t_player *pl, int x, int y, int cdir)
{
	pl->pos.x = x + 0.5;
	pl->pos.y = y + 0.5;
	pl->dir = 0.0;
	if (cdir == 'N')
		rotate_player(pl, NORTH_ANGLE);
	else if (cdir == 'E')
		rotate_player(pl, EAST_ANGLE);
	else if (cdir == 'S')
		rotate_player(pl, SOUTH_ANGLE);
	else if (cdir == 'W')
		rotate_player(pl, WEST_ANGLE);
}

char	parse_char(t_cub3d *cub3d, char c, int x, int y)
{
	if (!is_valid(c))
		cub3d->map.error = INVALID_CHAR;
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (cub3d->player.pos.x != -1)
			cub3d->map.error = MULTIPLE_PLAYER;
		parse_player(&cub3d->player, x + 1, y, c);
		c = '0';
	}
	if (c == ' ')
		c = '9';
	if (c == 'A')
	{
		add_back_monster(cub3d, new_monster((t_pointd){.x = x + 1 + 0.5, .y = y
				+ 0.5}, M_HP));
		c = '0';
	}
	return (c);
}
