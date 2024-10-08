/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_n_ceil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:10:03 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/18 11:11:10 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_faded_color(t_cub3d *c, int color, int line_height, double sens)
{
	const double	img_h2 = 0.5 * c->mlx.mlx_img.dim.height;
	double			distance;
	double			fade;

	distance = (sens * (c->player.view_height + c->player.walk_height_shift)
			- img_h2 * c->map.wall_heightscale) / (line_height - img_h2);
	fade = LUM_FADE_DIST / (LUM_FADE_DIST + distance * distance);
	return (((int)(((color >> 16) & 255) * fade) << 16)
		+ ((int)(((color >> 8) & 255) * fade) << 8)
		+ (int)((color & 255) * fade));
}

void	draw_floor(t_cub3d *c)
{
	t_pt2d	p0;
	t_pt2d	p1;
	int		ymax;

	p0 = (t_pt2d){.x = 0, .y = (c->mlx.mlx_img.dim.height >> 1)};
	p1 = (t_pt2d){.x = c->mlx.mlx_img.dim.width - 1, .y = p0.y};
	ymax = c->mlx.mlx_img.dim.height - 1;
	while (p0.y < ymax)
	{
		p0.color = get_faded_color(c, c->mlx.color_floor, p0.y, -1.0);
		draw_line(&c->mlx.mlx_img, p0, p1);
		p0.y++;
		p1.y++;
	}
}

void	draw_ceil(t_cub3d *c)
{
	t_pt2d	p0;
	t_pt2d	p1;
	int		ymax;

	p0 = (t_pt2d){.x = 0, .y = 0};
	p1 = (t_pt2d){.x = c->mlx.mlx_img.dim.width - 1, .y = 0};
	ymax = (c->mlx.mlx_img.dim.height >> 1) - 1;
	while (p0.y < ymax)
	{
		p0.color = get_faded_color(c, c->mlx.color_ceil, p0.y, 1.0);
		draw_line(&c->mlx.mlx_img, p0, p1);
		p0.y++;
		p1.y++;
	}
}

void	draw_floor_n_ceil(t_cub3d *c)
{
	if (c->game.rendering_mode == RENDER_COLOR
		|| c->mlx.text[TXID_CEIL].ptr == NULL)
		draw_ceil(c);
	if (c->game.rendering_mode == RENDER_COLOR
		|| c->mlx.text[TXID_FLOOR].ptr == NULL)
		draw_floor(c);
}
