/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:20:23 by sngantch          #+#    #+#             */
/*   Updated: 2025/03/15 16:02:38 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				current_pos;
	int				push_price;
	bool			above_median;
	bool			cheapeast;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				stack_init(t_stack **a, char **av, bool flag_ac_2);

char				**ft_split(char const *s, char c);
t_stack				*find_last_node(t_stack *head);
int					stack_len(t_stack *stack);
void				append_node(t_stack **stack, int nbr);
t_stack				*find_smallest(t_stack *stack);
t_stack				*return_cheapest(t_stack *stack);
t_stack				*find_last_node(t_stack *head);

void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **b, t_stack **a);

void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);

void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);

void				set_current_position(t_stack *stack);
void				set_price(t_stack *a, t_stack *b);
void				set_cheapest(t_stack *b);
void				init_nodes(t_stack *a, t_stack *b);

void				free_matrix(char **av);
void				free_stack(t_stack **stack);
void				error_free(t_stack **a, char **av, bool flag_ac_2);
int					error_syntax(char *str_nb);
int					error_repetition(t_stack *a, int nb);

bool				stack_sorted(t_stack *stack);
void				three_sort(t_stack **a);
void				handle_five(t_stack **a, t_stack **b);
void				finish_rotation(t_stack **stack, t_stack *top_node,
						char stack_name);
void				push_swap(t_stack **a, t_stack **b);

#endif