/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:23:12 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/10 17:50:45 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

inline static void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	quicksort_int(int *tab, int nb_elem)
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
			swap(tab + a, tab + b);
			a++;
			b--;
		}
	}
	if (b > 0)
		quicksort(tab, b + 1);
	if (a < nb_elem - 1)
		quicksort(&tab[a], nb_elem - a);
}

inline static void	swap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	quicksort(void **tab, int nb_elem)
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
			swap(tab + a, tab + b);
			a++;
			b--;
		}
	}
	if (b > 0)
		quicksort(tab, b + 1);
	if (a < nb_elem - 1)
		quicksort(&tab[a], nb_elem - a);
}
