/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:15:24 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/07 21:59:48 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_scaninfo(t_raycast *r, bool vertical, t_point mpos,
		t_scaninfo *si)
{
	if (vertical)
		si->distance = r->v_dist - r->v_dist_inc;
	else
		si->distance = r->h_dist - r->h_dist_inc;
	si->mpos = mpos;
}

static bool	find_item(t_cub3d *cub, t_pointd pos, char item)
{
	bool	is_monster;

	is_monster = monster_is_present(cub, pos);
	if (item != '0' || is_monster)
		return (true);
	return (false);
}

static void	cast_ray(t_cub3d *c, t_raycast *r, t_point mpos, t_scaninfo *si)
{
	const t_size2i	step = {.x = r->v_inc.x, .y = r->h_inc.y};
	bool			hits;
	bool			vertical;

	hits = false;
	while (!hits)
	{
		if (r->v_dist < r->h_dist)
		{
			r->v_dist += r->v_dist_inc;
			mpos.x += step.x;
			vertical = true;
		}
		else
		{
			r->h_dist += r->h_dist_inc;
			mpos.y += step.y;
			vertical = false;
		}
		si->item = c->map.m[mpos.y][mpos.x];
		hits = find_item(c, (t_pointd){.x = mpos.x, .y = mpos.y}, si->item);
	}
	set_scaninfo(r, vertical, mpos, si);
}

/* Scanne la map depuis la vue du joueur et renseingne 'si' avec l'element
 * trouvé (mur, porte, ...), ses coordonnées de map et sa distance au joueur.
 * 'angle' permet de scanner dans la direction du joueur + 'angle'
 * Renvoie l'element trouvé.
 */
int	scan_in_front(t_cub3d *c, t_scaninfo *si, double angle)
{
	t_raycast	ray;

	ray.angle = angles_add(c->player.dir, angle);
	init_ray_h_inter(&ray, ray.angle, c->player.pos);
	init_ray_v_inter(&ray, ray.angle, c->player.pos);
	cast_ray(c, &ray, (t_point){.x = c->player.pos.x, .y = c->player.pos.y},
		si);
	return (si->item);
}
