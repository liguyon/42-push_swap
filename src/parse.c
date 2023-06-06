/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:58:47 by liguyon           #+#    #+#             */
/*   Updated: 2023/06/06 23:54:59 by liguyon          ###   ########.fr       */
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

static int	check_duplicate(int n, int *tab, int size)
{
	while (--size >= 0)
	{
		if (tab[size] == n)
			return (E_ARGS);
	}
	return (E_OK);
}

int	parse(int count, char *content[], int *out)
{
	int		i;
	int		n;

	i = -1;
	while (++i < count)
	{
		if (check_value(content[i]) != E_OK)
			return (E_ARGS);
		n = ft_atoi(content[i]);
		if (check_duplicate(n, out, i) != E_OK)
			return (E_ARGS);
		out[i] = n;
	}
	return (E_OK);
}
