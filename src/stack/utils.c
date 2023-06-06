/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:16:01 by liguyon           #+#    #+#             */
/*   Updated: 2023/06/06 20:42:14 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_push(t_stack *this, int item)
{
	int		*content;
	t_list	*new;

	content = malloc(sizeof(item));
	if (content == NULL)
		return (E_MALLOC);
	*content = item;
	new = ft_lstnew(content);
	if (new == NULL)
		return (E_MALLOC);
	ft_lstadd_front(&this->items, new);
	this->top++;
	return (E_OK);
}

int	stack_pop(t_stack *this)
{
	t_list	*lst;
	int		value;

	lst = this->items;
	value = stack_peek(this);
	this->items = lst->next;
	ft_lstdelone(lst, free);
	this->top--;
	return (value);
}

int	stack_peek(t_stack *this)
{
	t_list	*lst;

	lst = this->items;
	return (*((int *)lst->content));
}

int	stack_size(t_stack *this)
{
	return (this->top + 1);
}

int	stack_is_empty(t_stack *this)
{
	return (this->items == NULL);
}
