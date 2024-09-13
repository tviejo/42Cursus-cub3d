/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:58:22 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/13 09:23:58 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_monsters	*new_monster(t_pointd pos, int hp)
{
	static int	id = 0;
	t_monsters	*new;

	new = malloc(sizeof(t_monsters));
	if (!new)
		return (NULL);
	new->id = id;
	new->pos = pos;
	new->hp = hp;
	new->next = NULL;
	new->random = rand() % 8;
	id++;
	return (new);
}

void	add_back_monster(t_cub3d *cub, t_monsters *new)
{
	t_monsters	*tmp;

	if (cub->nb_monsters + 1 >= MAX_MONSTERS + cub->game.difficulty
		* MAX_MONSTERS_PER_DIFFICULTY)
		return (free(new));
	cub->nb_monsters++;
	if (!cub->monsters)
	{
		cub->monsters = new;
		return ;
	}
	tmp = cub->monsters;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	clear_monsters(t_cub3d *cub)
{
	t_monsters	*tmp;

	while (cub->monsters)
	{
		tmp = cub->monsters;
		cub->monsters = cub->monsters->next;
		free(tmp);
	}
}

void	delete_monster(t_cub3d *cub, int id)
{
	t_monsters	*tmp;
	t_monsters	*prev;

	cub->nb_monsters--;
	tmp = cub->monsters;
	prev = NULL;
	while (tmp)
	{
		if (tmp->id == id)
		{
			if (prev)
				prev->next = tmp->next;
			else
				cub->monsters = tmp->next;
			free(tmp);
			play_sound(SND_MONSTER_DEATH, cub);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
