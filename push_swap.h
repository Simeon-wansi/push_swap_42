/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:20:23 by sngantch          #+#    #+#             */
/*   Updated: 2025/03/13 20:29:10 by sngantch         ###   ########.fr       */
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
	int					current_pos;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapeast;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

void					stack_init(t_stack_node **a, char **av, bool flag_ac_2);

char					**ft_split(char const *s, char c);
t_stack_node			*find_last_node(t_stack_node *head);
int						stack_len(t_stack_node *stack);
void					append_node(t_stack_node **stack, int nbr);
t_stack_node			*find_smallest(t_stack_node *stack);
t_stack_node			*return_cheapest(t_stack_node *stack);
t_stack_node			*find_last_node(t_stack_node *head);

void					pa(t_stack_node **a, t_stack_node **b);
void					pb(t_stack_node **b, t_stack_node **a);

void					ra(t_stack_node **a);
void					rb(t_stack_node **b);
void					rr(t_stack_node **a, t_stack_node **b);

void					rra(t_stack_node **a);
void					rrb(t_stack_node **b);
void					rrr(t_stack_node **a, t_stack_node **b);

void					sa(t_stack_node **a);
void					sb(t_stack_node **b);
void					ss(t_stack_node **a, t_stack_node **b);

void					set_current_position(t_stack_node *stack);
void					set_price(t_stack_node *a, t_stack_node *b);
void					set_cheapest(t_stack_node *b);
void					init_nodes(t_stack_node *a, t_stack_node *b);

void					free_matrix(char **av);
void					free_stack(t_stack_node **stack);
void					error_free(t_stack_node **a, char **av, bool flag_ac_2);
int						error_syntax(char *str_nb);
int						error_repetition(t_stack_node *a, int nb);

bool					stack_sorted(t_stack_node *stack);
void					three_sort(t_stack_node **a);
void					handle_five(t_stack_node **a, t_stack_node **b);
void	finish_rotation(t_stack_node **stack,
						t_stack_node *top_node,
						char stack_name);
void					push_swap(t_stack_node **a, t_stack_node **b);

#endif