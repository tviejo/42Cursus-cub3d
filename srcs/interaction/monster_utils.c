/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:27:44 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/08 18:35:43 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_monster_health(t_cub3d *cub, t_point pos)
{
	t_monsters	*tmp;

	tmp = cub->monsters;
	while (tmp)
	{
		if ((int)tmp->pos.x == pos.x && (int)tmp->pos.y == pos.y)
		{
			mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, WINDOW_WIDTH / 2
				- 100, 20, COL_WHITE, "Monster id:");
			mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, WINDOW_WIDTH / 2
				- 30, 20, COL_WHITE, ft_itoa(tmp->id));
			mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, WINDOW_WIDTH / 2
				- 100, 35, COL_WHITE, "HP:");
			mlx_string_put(cub->mlx.mlx_ptr, cub->mlx.win_ptr, WINDOW_WIDTH / 2
				- 80, 35, COL_WHITE, ft_itoa(tmp->hp));
		}
		tmp = tmp->next;
	}
}

static void	remove_monster_hp(t_cub3d *cub, t_point pos, int distance)
{
	t_monsters				*tmp;
	static struct timeval	old_time = {.tv_sec = 0, .tv_usec = 0};

	if (old_time.tv_sec != cub->game.last_time.tv_sec)
	{
		old_time = cub->game.last_time;
		tmp = cub->monsters;
		while (tmp)
		{
			if ((int)tmp->pos.x == pos.x && (int)tmp->pos.y == pos.y)
			{
				usleep(100000);
				play_sound(MONSTER_DAMAGE);
				if (distance == 0)
					tmp->hp -= 5;
				else
					tmp->hp -= 5 / distance;
				if (tmp->hp <= 0)
					delete_monster(cub, tmp->id);
				return ;
			}
			tmp = tmp->next;
		}
	}
}

void	shoot_monsters(t_cub3d *cub)
{
	t_scaninfo	info;
	int			random_angle;

	random_angle = rand() % 2 - 1;
	scan_in_front(cub, &info, random_angle);
	if (info.item == '0' && cub->inputs.shoot)
		remove_monster_hp(cub, info.mpos, info.distance);
	scan_in_front(cub, &info, 0);
	print_monster_health(cub, info.mpos);
}

void	sound_close_monster(t_cub3d *cub)
{
	t_monsters	*tmp;
	static struct timeval	old_time = {.tv_sec = 0, .tv_usec = 0};

	if (labs(old_time.tv_sec - cub->game.last_time.tv_sec) > 3)
	{
		old_time = cub->game.last_time;
		tmp = cub->monsters;
		while (tmp)
		{
			if (labs((int)tmp->pos.x - (int)cub->player.pos.x) < 3
				&& labs((int)tmp->pos.y - (int)cub->player.pos.y) < 3)
				play_sound(MONSTER_CLOSE_2);
			tmp = tmp->next;
		}
	}
}
