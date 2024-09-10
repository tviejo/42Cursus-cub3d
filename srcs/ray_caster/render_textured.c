/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textured.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 23:23:32 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/10 17:01:10 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*inline static double	mod1(double n)
{
	//m = x - (float)(int)x;
	//m += (float)(m<0.f);
	return (n - (int)n + (n < 0.0));
}*/

inline static int	iabs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static double	get_wall_distance(t_cub3d *c, t_raycast *r)
{
	double		p_wall_dist;
	double		steps;

	r->wall_orientation = get_wall_orientation(r->angle, r->vertical_wall);
	if (r->vertical_wall)
	{
		steps = iabs(r->mapc.x - (int)c->player.pos.x) - 1;
		r->wall_inter.x = r->v_inter.x + steps;
		r->wall_inter.y = r->v_inter.y + steps * r->v_inc.y;
		p_wall_dist = r->v_dist - r->v_dist_inc;
	}
	else
	{
		steps = iabs(r->mapc.y - (int)c->player.pos.y) - 1;
		r->wall_inter.x = r->h_inter.x + steps * r->h_inc.x;
		r->wall_inter.y = r->h_inter.y + steps;
		p_wall_dist = r->h_dist - r->h_dist_inc;
	}
	p_wall_dist *= cos(c->player.dir - r->angle);
	return (p_wall_dist);
}

static int	get_tex_x(t_raycast *r, double scale)
{
	if (r->wall_orientation == North)
		return ((r->wall_inter.x - r->mapc.x) * scale);
	if (r->wall_orientation == South)
		return ((r->mapc.x + 1 - r->wall_inter.x) * scale);
	if (r->wall_orientation == East)
		return ((r->wall_inter.y - r->mapc.y) * scale);
	return ((r->mapc.y + 1 - r->wall_inter.y) * scale);
}

int	render_ray_tex_init(t_cub3d *c, t_raycast *rc, t_render_textured *r,
							int item)
{
	r->w_dist = get_wall_distance(c, rc);
	r->tex = get_wall_texture(c, rc->wall_orientation, r->w_dist, item);
	if (r->tex->ptr == NULL)
	{
		render_ray_colored(c, rc, item);
		return (EXIT_FAILURE);
	}
	c->mlx.slices_zbuffer[rc->column] = r->w_dist;
	r->shade = TEX_FADE_DIST / (TEX_FADE_DIST + r->w_dist * r->w_dist);
	r->tex_modulo_m1 = TEX_SIZE - 1;
	r->tex_x = get_tex_x(rc, TEX_SCALE) & r->tex_modulo_m1;
	r->height = c->map.wall_heightscale * c->mlx.mlx_img.dim.height / r->w_dist;
	r->y0 = (c->player.view_height + c->player.walk_height_shift) / r->w_dist
		+ ((c->mlx.mlx_img.dim.height - r->height) >> 1);
	return (EXIT_SUCCESS);
}
