/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textured.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 23:23:32 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/14 23:49:33 by ade-sarr         ###   ########.fr       */
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

static double	get_wall_distance(t_cub3d *c, t_raycast *rc)
{
	double		p_wall_dist;
	double		steps;

	rc->wall_orientation = get_wall_orientation(rc->angle, rc->vertical_wall);
	if (rc->vertical_wall)
	{
		steps = iabs(rc->mapc.x - (int)c->player.pos.x) - 1;
		rc->wall_inter.x = rc->v_inter.x + steps;
		rc->wall_inter.y = rc->v_inter.y + steps * rc->v_inc.y;
		p_wall_dist = rc->v_dist - rc->v_dist_inc;
	}
	else
	{
		steps = iabs(rc->mapc.y - (int)c->player.pos.y) - 1;
		rc->wall_inter.x = rc->h_inter.x + steps * rc->h_inc.x;
		rc->wall_inter.y = rc->h_inter.y + steps;
		p_wall_dist = rc->h_dist - rc->h_dist_inc;
	}
	p_wall_dist *= cos(c->player.dir - rc->angle);
	return (p_wall_dist);
}

static int	get_tex_x(t_raycast *rc, double scale)
{
	if (rc->wall_orientation == North)
		return ((rc->wall_inter.x - rc->mapc.x) * scale);
	if (rc->wall_orientation == South)
		return ((rc->mapc.x + 1 - rc->wall_inter.x) * scale);
	if (rc->wall_orientation == East)
		return ((rc->wall_inter.y - rc->mapc.y) * scale);
	return ((rc->mapc.y + 1 - rc->wall_inter.y) * scale);
}

int	render_ray_tex_init(t_cub3d *c, t_raycast *rc, t_render_tex *r,
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
	//printf("view_height: %.2f  walk_height_shift: %.2f  r->w_dist: %.2f  mlx_img.dim.height: %i  r->height: %i\n", c->player.view_height, c->player.walk_height_shift, r->w_dist, 
	//	c->mlx.mlx_img.dim.height, r->height);
	//exit(0);
	return (EXIT_SUCCESS);
}
