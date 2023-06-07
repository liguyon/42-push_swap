/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:44:32 by liguyon           #+#    #+#             */
/*   Updated: 2023/06/07 17:44:57 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(int *tab, int start, int end)
{
	int	pivot;
	int	p_index;
	int	i;

	p_index = start;
	pivot = tab[end];
	i = start;
	while (i < end)
	{
		if (tab[i] <= pivot)
		{
			swap(&tab[i], &tab[p_index]);
			p_index++;
		}
		i++;
	}
	swap(&tab[p_index], &tab[end]);
	return (p_index);
}

void	quicksort(int *tab, int start, int end)
{
	int	p_index;

	if (start < end)
	{
		p_index = partition(tab, start, end);
		quicksort(tab, start, p_index - 1);
		quicksort(tab, p_index + 1, end);
	}
}
