/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:20:32 by sngantch          #+#    #+#             */
/*   Updated: 2025/03/08 17:47:33 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

/* Create a stack with the command line values 
check are embeded in thee creation itself
Duplicates values
Over | underflow
syntax errors*/

void	stack_init(t_stack_node **a, char **av, bool flag_ac_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			error_free(a, av, flag_ac_2);
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, av, flag_ac_2);
		if (error_repetition(*a, (int)nbr))
			error_free(a, av, flag_ac_2);
		append_node(a, (int)nbr);
		++i;
	}
	if (flag_ac_2)
		free_matrix(av);
}

void	error_free(t_stack_node **a, char **av, bool flag_ac_2)
{
	t_stack_node *current;
	t_stack_node *next;

	current = *a;
	while(current)
	{
		next = current->next;
		free(current);
		current =  next;
	}
	*a =  NULL;
	
	
	exit(2);
}

int	error_repetition(t_stack_node *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (a);
}

int error_syntax(const char *str)
{
	int i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
		
	if (str[i] == '\0')
		return (1);
	while(str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	stack_init(t_stack_node **a, char **av, bool flag_ac_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			error_free(a, av, flag_ac_2);
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, av, flag_ac_2);
		if (error_repetition(*a, (int)nbr))
			error_free(a, av, flag_ac_2);
		append_node(a, (int)nbr);
		++i;
	}
	if (flag_ac_2)
		free_matrix(av);
}
