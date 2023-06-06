/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:18:28 by liguyon           #+#    #+#             */
/*   Updated: 2023/06/06 23:07:02 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_op_rotate(t_stack *this)
{
	t_list	*temp;
	t_list	*lst;

	if (stack_size(this) < 2)
		return ;
	temp = this->items;
	this->items = this->items->next;
	lst = this->items;
	temp->next = NULL;
	ft_lstadd_back(&lst, temp);
}

void	stack2_rotate(t_stack2 *this, char op)
{
	if (op == 'a' || op == 'r')
		stack_op_rotate(this->a);
	if (op == 'b' || op == 'r')
		stack_op_rotate(this->b);
	ft_printf("r%c\n", op);
}

static void	stack_op_reverse_rotate(t_stack *this)
{
	t_list	*lst;
	t_list	*before_last;

	if (stack_size(this) < 2)
		return ;
	lst = this->items;
	while (lst->next != NULL)
	{
		before_last = lst;
		lst = lst->next;
	}
	before_last->next = NULL;
	ft_lstadd_front(&this->items, lst);
}

void	stack2_reverse_rotate(t_stack2 *this, char op)
{
	if (op == 'a' || op == 'r')
		stack_op_reverse_rotate(this->a);
	if (op == 'b' || op == 'r')
		stack_op_reverse_rotate(this->b);
	ft_printf("rr%c\n", op);
}
