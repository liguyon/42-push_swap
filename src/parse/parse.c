/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:58:47 by liguyon           #+#    #+#             */
/*   Updated: 2023/06/07 17:59:32 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	check_value(const char *nbr)
{
	int		i;
	long	n;

	if (!*nbr)
		return (E_ARGS);
	i = -1;
	while (nbr[++i])
	{
		if (!ft_isdigit(nbr[i]))
		{
			if ((nbr[i] == '-' || nbr[i] == '+') && i == 0)
				continue ;
			return (E_ARGS);
		}
	}
	n = ft_atol(nbr);
	if (n > INT_MAX || n < INT_MIN)
		return (E_ARGS);
	return (E_OK);
}

static int	check_duplicate(int *sorted, int size)
{
	while (--size > 0)
	{
		if (sorted[size] == sorted[size - 1])
			return (E_ARGS);
	}
	return (E_OK);
}

static int	*array_dup(int *tab, int size)
{
	int	*res;

	res = malloc(sizeof(int) * size);
	if (res == NULL)
		return (NULL);
	while (--size >= 0)
		res[size] = tab[size];
	return (res);
}

int	parse(int count, char *content[], int *out)
{
	int		i;
	int		*tmp;

	i = -1;
	while (++i < count)
	{
		if (check_value(content[i]) != E_OK)
			return (E_ARGS);
		out[i] = ft_atoi(content[i]);
	}
	tmp = array_dup(out, count);
	if (tmp == NULL)
		return (E_MALLOC);
	quicksort(tmp, 0, count - 1);
	if (check_duplicate(tmp, count) != E_OK)
		return (E_ARGS);
	free(tmp);
	return (E_OK);
}
