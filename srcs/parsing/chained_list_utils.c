/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:58:22 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/07 18:10:27 by tviejo           ###   ########.fr       */
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
	id++;
	return (new);
}

void	add_back_monster(t_cub3d *cub, t_monsters *new)
{
	t_monsters	*tmp;

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
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
