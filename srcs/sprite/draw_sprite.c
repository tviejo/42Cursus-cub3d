/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:46:36 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/13 10:32:37 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	get_angle(t_pointd pos, t_player *pl)
{
	const double	dx = pos.x - pl->pos.x;
	const double	dy = pl->pos.y - pos.y;

	return (angles_add(atan2(dy, dx), -pl->dir));
}

static void	clip_columns(t_image *img, int *first, int *maxcol)
{
	if (*first < 0)
		*first = 0;
	if (*maxcol > img->dim.width)
		*maxcol = img->dim.width;
}

/*dist_to_plane = c->mlx.mlx_img.dim.height
		/ tan(0.5 * c->player.vertical_fov);
	ray.column = 0;
	ray.angle = angles_add(atan2(0.5 * c->mlx.mlx_img.dim.width
				- (ray.column - 0.5), dist_to_plane), c->player.dir);
	
	p_wall_dist *= cos(c->player.dir - r->angle);
	height = c->map.wall_heightscale * c->mlx.mlx_img.dim.height / p_wall_dist;
	*/

void	draw_sprite(t_cub3d *c, t_sprite *spr, int img_num)
{
	int		width;
	int		column;
	int		col0;
	int		maxcol;
	double	dist2plane;

	spr->dist *= cos(spr->angle);
	spr->height = spr->scale * c->mlx.mlx_img.dim.height / spr->dist;
	width = spr->height * spr->ratio_w_h;
	dist2plane = c->mlx.mlx_img.dim.height / tan(0.5 * c->player.vertical_fov);
	column = 0.5 * c->mlx.mlx_img.dim.width + 0.5
		- tan(spr->angle) * dist2plane - (width >> 1);
	col0 = column;
	maxcol = column + width;
	clip_columns(&c->mlx.mlx_img, &column, &maxcol);
	while (column < maxcol)
	{
		spr->angle = angles_add(atan2(0.5 * c->mlx.mlx_img.dim.width
					- (column - 0.5), dist2plane), c->player.dir);
		spr->column = column;
		spr->x_spot = (column - col0) / (double)width;
		draw_slice(c, spr, img_num);
		column++;
	}
}

void	draw_monsters(t_cub3d *cub)
{
	static t_monsters	*monsters[MAX_MONSTERS*5];
	t_monsters			*m;
	const t_pointd		ppos = cub->player.pos;
	t_sprite *const		spr = &cub->sprites[SPR_MONSTER1];
	int					i;

	i = 0;
	m = cub->monsters;
	while (m)
	{
		m->dist2_to_player = (m->pos.x - ppos.x) * (m->pos.x - ppos.x)
			+ (m->pos.y - ppos.y) * (m->pos.y - ppos.y);
		monsters[i++] = m;
		m = m->next;
	}
	qsort_monsters(monsters, i);
	while (i--)
	{
		spr->pos = monsters[i]->pos;
		spr->dist = sqrt(monsters[i]->dist2_to_player);
		spr->angle = get_angle(monsters[i]->pos, &cub->player);
		if (spr->angle > 2 * M_PI - 0.5 * cub->player.vertical_fov
			|| spr->angle < 0.5 * cub->player.vertical_fov)
			draw_sprite(cub, spr, cub->game.last_tod.tv_sec & 3);
	}
}

//printf("pl: (%.2f,%.2f)  monster %i: (%.2f,%.2f)  angle: %.1f\n", cub->player.pos.x, cub->player.pos.y,
		//	i, monsters[i]->pos.x, monsters[i]->pos.y, angle * 180.0 / M_PI);