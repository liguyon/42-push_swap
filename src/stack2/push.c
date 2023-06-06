/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:30:29 by liguyon           #+#    #+#             */
/*   Updated: 2023/06/06 22:24:43 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_op_push(t_stack *to, t_stack *from)
{
	t_list	*top;

	top = from->items;
	from->items = from->items->next;
	ft_lstadd_front(&to->items, top);
	to->top++;
	from->top--;
}

void	stack2_push(t_stack2 *this, char op)
{
	if (op == 'a')
		stack_op_push(this->a, this->b);
	else if (op == 'b')
		stack_op_push(this->b, this->a);
	ft_printf("p%c\n", op);
}
