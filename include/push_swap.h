/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:29:13 by liguyon           #+#    #+#             */
/*   Updated: 2023/06/06 18:38:46 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

enum e_errno
{
	E_OK,
	E_MALLOC
};

/*
	A stack implementation using a linked list to store its items.
*/
typedef struct s_stack	t_stack;
struct s_stack
{
	t_list	*items;
	int		top;
};

// Initialize the stack
void	stack_init(t_stack *this);

// Clear any memory that has been allocated for the stack and
// reinitialize its elements
void	stack_destroy(t_stack *this);

// Add an element to the top of the stack
int		stack_push(t_stack *this, int item);

// Remove the top element of the stack
void	stack_pop(t_stack *this);

// Return the top element of the stack
// Careful: the user is responsible to provide a non empy stack
int		stack_peek(t_stack *this);

// Return the size of the stack
int		stack_size(t_stack *this);

// Check if the stack is empty or not
int		stack_is_empty(t_stack *this);

// !!!
// For debugging - remove before final push
void	stack_print_items(t_stack *this);

#endif