/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:23:12 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/15 10:20:57 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline static void	swap_int(int *elm_a, int *elm_b)
{
	int	tmp;

	tmp = *elm_a;
	*elm_a = *elm_b;
	*elm_b = tmp;
}

void	qsort_int(int *tab, int nb_elem)
{
	int	pivot;
	int	a;
	int	b;

	pivot = tab[nb_elem >> 1];
	a = 0;
	b = nb_elem - 1;
	while (a <= b)
	{
		while (tab[a] < pivot)
			a++;
		while (tab[b] > pivot)
			b--;
		if (a <= b)
		{
			swap_int(tab + a, tab + b);
			a++;
			b--;
		}
	}
	if (b > 0)
		qsort_int(tab, b + 1);
	if (a < nb_elem - 1)
		qsort_int(&tab[a], nb_elem - a);
}

inline static void	swap(t_monsters **elm_a, t_monsters **elm_b)
{
	t_monsters	*tmp;

	tmp = *elm_a;
	*elm_a = *elm_b;
	*elm_b = tmp;
}

void	qsort_monsters(t_monsters **tab, int nb_elem)
{
	double	pivot;
	int		a;
	int		b;

	pivot = tab[nb_elem >> 1]->dist2_to_player;
	a = 0;
	b = nb_elem - 1;
	while (a <= b)
	{
		while (tab[a]->dist2_to_player < pivot)
			a++;
		while (tab[b]->dist2_to_player > pivot)
			b--;
		if (a <= b)
		{
			swap(tab + a, tab + b);
			a++;
			b--;
		}
	}
	if (b > 0)
		qsort_monsters(tab, b + 1);
	if (a < nb_elem - 1)
		qsort_monsters(&tab[a], nb_elem - a);
}
