/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:20:23 by sngantch          #+#    #+#             */
/*   Updated: 2025/03/08 18:09:27 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					pos;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

void					tiny_sort(t_stack_node **a);

char					**ft_split(char const *s, char c);
t_stack_node			*find_last_node(t_stack_node *head);
int						stack_len(t_stack_node *stack);
void					append_node(t_stack_node **stack, int nbr);
t_stack_node			*find_smallest(t_stack_node *stack);
t_stack_node			*find_last_node(t_stack_node *head);

static void				rotate(t_stack_node **stack);
void					ra(t_stack_node **a);
void					rb(t_stack_node **b);
void					rr(t_stack_node **a, t_stack_node **b);

static void				swap(t_stack_node **head);
void					sa(t_stack_node **a);
void					sb(t_stack_node **b);
void					ss(t_stack_node **a, t_stack_node **b);

static void				push(t_stack_node **dest, t_stack_node **src);
void					pa(t_stack_node **a, t_stack_node **b);
void					pa(t_stack_node **b, t_stack_node **a);

static void				reverse_rotate(t_stack_node **stack);
void					rra(t_stack_node **a);
void					rrb(t_stack_node **b);
void					rrr(t_stack_node **a, t_stack_node **b);

void					init_nodes(t_stack_node *a, t_stack_node *b);
void					stack_init(t_stack_node **a, char **av, bool flag_ac_2);
#endif