/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:18:41 by liguyon           #+#    #+#             */
/*   Updated: 2023/06/06 22:46:44 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack2_destroy(t_stack2 *this)
{
	if (this->a)
	{
		stack_destroy(this->a);
		free(this->a);
		this->a = NULL;
	}
	if (this->b)
	{
		stack_destroy(this->b);
		free(this->b);
		this->b = NULL;
	}
}

int	stack2_init(t_stack2 *this, int *content, int size)
{
	this->a = malloc(sizeof(t_stack));
	this->b = malloc(sizeof(t_stack));
	if (this->a == NULL || this->b == NULL)
	{
		stack2_destroy(this);
		return (E_MALLOC);
	}
	stack_init(this->a);
	stack_init(this->b);
	while (--size >= 0)
	{
		if (stack_push(this->a, content[size]) != E_OK)
		{
			stack2_destroy(this);
			return (E_MALLOC);
		}
	}
	return (E_OK);
}
