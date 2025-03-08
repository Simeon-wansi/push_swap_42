/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 04:56:14 by sngantch          #+#    #+#             */
/*   Updated: 2025/03/08 18:33:23 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// /* The loop decade once
//  cheapeast_node is a 
//  relatove target_node tops in b*/

// static void	rotate_both(t_stack_node **a, t_stack_node **b,
// 		t_stack_node *cheapest_node)
// {
// 	while (*a != cheapest_node->target_node && *b != cheapest_node)
// 		rr(a, b, false);
// 	set_current_position(*a);
// 	set_current_position(*b);
// }

// static void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
// 		t_stack_node *cheapest_node)
// {
// 	while (*a != cheapest_node->target_node && *b != cheapest_node)
// 		rrr(a, b, false);
// 	set_current_position(a);
// 	set_current_position(b);
// }

// /* conclude the rotation of the staks*/

// void	finish_rotation(t_stack_node **stack, t_stack_node *top_node,
// 		char stack_name)
// {
// 	while (*stack != top_node)
// 	{
// 		if (stack_name == 'a')
// 		{
// 			if (top_node->above_median)
// 				ra(stack, false);
// 			else
// 				rra(stack, false);
// 		}
// 		else if (stack_name == 'b')
// 		{
// 			if (top_node->above_median)
// 				rb(stack, false);
// 			else
// 				rrb(stack, false);
// 		}
// 	}
// }

// /* Move the node from b to a 
// with metadata available in the node 
// 1) make the target nodes emerge
// 2) push in A*/

// static void	move_nodes(t_stack_node **a, t_stack_node **b)
// {
// 	t_stack_node	*cheapest_node;

// 	cheapest_node = return_cheapest(*b);
// 	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
// 		rotate_both(a, b, cheapest_node);
//     else if (!(cheapest_node->target_node->above_median))
//         reverse_rotate_both(a, b, cheapest_node);
//     finish_rotation(b, cheapest_node, 'b');
// 	finish_rotation(a, ch)
// }


int	get_max_bits(t_stack_node *stack)
{
	int	max;
	int	bits;
	t_stack_node *current;

	max = 0;
	bits = 0;
	current = stack;
	while (current)
	{
		if (stack->pos > max)
			max = stack->pos;
		current  = current->next;
	}
	while (max > 0)
	{
		max = max / 2;
		bits++;
	}
	return (bits);
}

void	radix_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	i;
	int	max_bits;
	int	bit_position;
	int	size;

	max_bits = get_max_bits(stack_a);
	bit_position = 0;
	while (bit_position < max_bits)
	{
		size = stack_len(stack_a);
		i = 0;
		while (i < size)
		{
			if (((*stack_a)->pos >> bit_position) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			i++;
		}
		// Remettre les éléments de B dans A
		while (stack_len(stack_b))
			pa(stack_b, stack_a);
		bit_position++;
	}
}