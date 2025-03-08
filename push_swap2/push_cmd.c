/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:15:24 by sngantch          #+#    #+#             */
/*   Updated: 2025/03/08 18:08:54 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_stack_node **dest, t_stack_node **src)
{
    t_stack_node *node_to_push;
    
    if (*src == NULL)
        return;
    node_to_push = *src;
    *src = (*src)->next;
    if(*src)
        (*src)->prev = NULL;
    node_to_push->prev = NULL;
    if (*dest == NULL)
    {
        *dest =  node_to_push;
        node_to_push->next = NULL;
    }
    else
    {
        node_to_push->next = *dest;
        node_to_push->next->prev =  node_to_push;
        *dest = node_to_push;
    }
}

void pa(t_stack_node **a, t_stack_node **b)
{
    push(a, b);
    write(1, "pa\n", 3);
}

void pa(t_stack_node **b, t_stack_node **a)
{
    push(b, a);
    write(1, "pb\n", 3);
}