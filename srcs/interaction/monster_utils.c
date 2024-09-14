/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:27:44 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/14 19:40:47 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_m(t_cub3d *cub, t_monsters *tmp)
{
	char	*info;

	mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, WINDOW_WIDTH / 2 - 100,
		30, COL_WHITE, "Monster id:");
	info = ft_itoa(tmp->id);
	mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, WINDOW_WIDTH / 2 + 20,
		30, COL_WHITE, info);
	free(info);
	mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, WINDOW_WIDTH / 2 - 100,
		50, COL_WHITE, "HP:");
	info = ft_itoa(tmp->hp);
	mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, WINDOW_WIDTH / 2 - 60,
		50, COL_WHITE, info);
	free(info);
}

static void	print_monster_health(t_cub3d *cub, t_point pos)
{
	t_monsters	*tmp;
	t_pointd	delta;

	tmp = cub->monsters;
	while (tmp)
	{
		delta = (t_pointd){.x = tmp->pos.x - pos.x, .y = tmp->pos.y - pos.y};
		if (fabs(delta.x) < M_HIT_BOX * 2 && fabs(delta.y) < M_HIT_BOX * 2)
		{
			print_m(cub, tmp);
			return ;
		}
		tmp = tmp->next;
	}
}

static void	remove_monster_hp(t_cub3d *cub, t_point pos, int distance)
{
	t_monsters	*tmp;
	double		delta_x;
	double		delta_y;

	tmp = cub->monsters;
	while (tmp)
	{
		delta_x = tmp->pos.x - pos.x;
		delta_y = tmp->pos.y - pos.y;
		if (fabs(delta_x) < M_HIT_BOX && fabs(delta_y) < 0.5)
		{
			usleep(100000);
			play_sound(SND_MONSTER_DAMAGE, cub);
			if (distance < 2)
				tmp->hp -= 5;
			else
				tmp->hp -= 5 / distance / 2 + 1;
			if (tmp->hp <= 0)
				delete_monster(cub, tmp->id);
			return ;
		}
		tmp = tmp->next;
	}
}

void	shoot_monsters(t_cub3d *cub)
{
	t_scaninfo	info;

	scan_in_front(cub, &info, 0);
	if (info.item == '0' && cub->inputs.shoot)
		remove_monster_hp(cub, info.mpos, info.distance);
	scan_in_front(cub, &info, 0);
	print_monster_health(cub, info.mpos);
}

void	sound_close_monster(t_cub3d *cub)
{
	t_monsters				*tmp;
	static struct timeval	old_time = {.tv_sec = 0, .tv_usec = 0};

	if (labs(old_time.tv_sec - cub->game.last_tod.tv_sec) > 3)
	{
		old_time = cub->game.last_tod;
		tmp = cub->monsters;
		while (tmp)
		{
			if (labs((int)tmp->pos.x - (int)cub->player.pos.x) < 3
				&& labs((int)tmp->pos.y - (int)cub->player.pos.y) < 3)
				play_sound(SND_MONSTER_CLOSE_2, cub);
			tmp = tmp->next;
		}
	}
}
