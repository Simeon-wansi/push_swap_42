/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 01:42:52 by sngantch          #+#    #+#             */
/*   Updated: 2025/03/08 16:36:39 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_last_node(t_stack_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

/*Find the smallest value*/
t_stack_node	*find_smallest(t_stack_node *stack)
{
	long			smallest;
	t_stack_node	*smallest_node;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack_node	*find_next_smallest(t_stack_node *stack, long smallest)
{
	t_stack_node	*next_smallest_node =  NULL;
	long			next_smallest = LONG_MAX;

	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->value > smallest && stack->value < next_smallest)
		{
			next_smallest = stack->value;
			next_smallest_node = stack;
		}
		stack = stack->next;
	}
	return (next_smallest_node);
}

int	stack_len(t_stack_node *stack)
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}

void position_init(t_stack_node *stack)
{
	if (stack == NULL)
		return;
	while(stack)
	{
		stack->pos = 0;
		stack = stack->next;
	}
}
void	set_position(t_stack_node *stack)
{
	int	i;
	t_stack_node *current;
	long current_min = LONG_MIN;
	t_stack_node* min_node;

	if (stack == NULL)
		return;
		
	position_int(stack);
	
	i = 0;
	while (i < stack_len(stack))
	{
		if (current->pos == 0 && current->value < current_min)
		{
			current_min = current->value;
			min_node = current;
		}
		if (min_node)
			min_node->pos =  i + 1;
		i++;
	}
}