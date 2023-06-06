/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:29:13 by liguyon           #+#    #+#             */
/*   Updated: 2023/06/06 23:38:59 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

enum e_errno
{
	E_OK,
	E_MALLOC,
	E_ARGS
};

/*
	An implementation of a stack using a linked list to store its items.
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

// Remove the top element of the stack and return it
// Careful: the user is responsible to provide a non empy stack
int		stack_pop(t_stack *this);

// Return the top element of the stack
// Careful: the user is responsible to provide a non empy stack
int		stack_peek(t_stack *this);

// Return the size of the stack
int		stack_size(t_stack *this);

// Check whether the stack is empty
int		stack_is_empty(t_stack *this);

// !!!
// For debugging - remove before final push
void	stack_print_items(t_stack *this);

////

/*
	Implementation of the two stacks used in push_swap and the
	permitted operations on them
*/
typedef struct s_stack2	t_stack2;
struct s_stack2
{
	t_stack	*a;
	t_stack	*b;
};

// Allocate memory for the 2 stacks and initialize them
int		stack2_init(t_stack2 *this, int *content, int size);

// Clear any memory that has been allocated for the stack2 and
// reinitialize its elements
void	stack2_destroy(t_stack2 *this);

// Operations on stacks as described in the subject
// op is the last letter of the operation
// for example: rra -> op = 'a'
//				ss -> op = 's'
void	stack2_swap(t_stack2 *this, char op);
void	stack2_push(t_stack2 *this, char op);
void	stack2_rotate(t_stack2 *this, char op);
void	stack2_reverse_rotate(t_stack2 *this, char op);

/////
int		parse(int count, char *content[], int *out);

#endif