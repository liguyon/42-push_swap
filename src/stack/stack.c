/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:39:15 by liguyon           #+#    #+#             */
/*   Updated: 2023/06/06 21:15:16 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *this)
{
	t_list	*lst;

	lst = NULL;
	this->top = -1;
	this->items = lst;
}

void	stack_destroy(t_stack *this)
{
	if (this->items != NULL)
		ft_lstclear(&this->items, free);
	stack_init(this);
}

void	stack_print_items(t_stack *this)
{
	t_list	*lst;

	if (stack_is_empty(this))
	{
		ft_printf("Stack is empty\n");
		return ;
	}
	lst = this->items;
	ft_printf("top\n-----\n");
	while (lst)
	{
		ft_printf("%d\n", *((int *)lst->content));
		lst = lst->next;
	}
	ft_printf("-----\nbottom\n\n");
}
