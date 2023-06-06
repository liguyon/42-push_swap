/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:58:15 by liguyon           #+#    #+#             */
/*   Updated: 2023/06/06 21:17:57 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_op_swap(t_stack *this)
{
	t_list	*first;
	t_list	*second_next;

	if (stack_size(this) > 2)
	{
		first = this->items;
		second_next = this->items->next->next;
		this->items = this->items->next;
		this->items->next = first;
		first->next = second_next;
	}
}

void	stack2_swap(t_stack2 *this, char op)
{
	if (op == 'a' || op == 's')
		stack_op_swap(this->a);
	if (op == 'b' || op == 's')
		stack_op_swap(this->b);
	ft_printf("s%c\n", op);
}
