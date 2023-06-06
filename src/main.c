/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:48:13 by liguyon           #+#    #+#             */
/*   Updated: 2023/06/07 00:01:34 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	raise_error(int errno)
{
	if (errno != 0)
		ft_perror("Error\n");
	exit(errno);
}

int	main(int ac, char *av[])
{
	enum e_errno	e;
	t_stack2		s;
	int				*tab;

	(void)e;
	if (ac >= 2)
	{
		tab = malloc(sizeof(*tab) * (ac - 1));
		if (tab == NULL)
			raise_error(E_MALLOC);
		if (parse(ac - 1, &av[1], tab) != E_OK)
			raise_error(E_ARGS);
		stack2_init(&s, tab, ac - 1);
		stack2_sort(&s);
		stack2_destroy(&s);
		free(tab);
	}
	exit(E_OK);
}
