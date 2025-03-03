/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 23:40:37 by sngantch          #+#    #+#             */
/*   Updated: 2025/03/03 17:36:32 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
# include "push_swap.h"

void	swap(int *tab, int len)
{
	int	temp;

	if (len < 2)
		return ;
	temp = tab[0];
	tab[0] = tab[1];
	tab[1] = temp;
}

void	ss(int *tab1, int len1, int *tab2, int len2)
{
	swap(tab1, len1);
	swap(tab2, len2);
	ft_printf("ss\n");
}

void	sa(int *tab, int len)
{
	swap(tab, len);
	ft_printf("sa\n");
}

void	sb(int *tab, int len)
{
	swap(tab, len);
	ft_printf("sb\n");
}

void	push(int *tab1, int *len1, int *tab2, int *len2)
{
	int	i;

	if (*len1 == 0)
		return ;
	i = *len2;
	while (i > 0)
	{
		tab2[i] = tab2[i - 1];
		i--;
	}
	tab2[0] = tab1[0];
	i = 0;
	while (i < *len1 - 1)
	{
		tab1[i] = tab1[i + 1];
		i++;
	}
	(*len1)--;
	(*len2)++;
}

void	pa(int *tab1, int *len1, int *tab2, int *len2)
{
	push(tab1, len1, tab2, len2);
	printf("pa\n");
}
void	pb(int *tab1, int *len1, int *tab2, int *len2)
{
	push(tab1, len1, tab2, len2);
	printf("pb\n");
}

void	rotate(int *tab, int len)
{
	int	temp;
	int	i;

	if (len < 2)
		return ;
	temp = tab[0];
	i = 0;
	while (i < len - 1)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[len - 1] = temp;
}

void	ra(int *tab, int len)
{
	rotate(tab, len);
	ft_printf("ra\n");
}

void	rb(int *tab, int len)
{
	rotate(tab, len);
	printf("rb\n");
}

void	rr(int *tab1, int len1, int *tab2, int len2)
{
	rotate(tab1, len1);
	rotate(tab2, len2);
	ft_printf("rr\n");
}

void	reverse(int *tab, int len)
{
	int	temp;
	int	i;

	if (len < 2)
		return ;
	temp = tab[len - 1];
	i = len - 1;
	while (i > 0)
	{
		tab[i] = tab[i - 1];
		i--;
	}
	tab[0] = temp;
}
void	rra(int *tab, int len)
{
	reverse(tab, len);
	ft_printf("rra\n");
}
void	rrb(int *tab, int len)
{
	reverse(tab, len);
	ft_printf("rrb\n");
}

void	rrr(int *tab1, int len1, int *tab2, int len2)
{
	reverse(tab1, len1);
	reverse(tab2, len2);
	ft_printf("rrr\n");
}
// #include <stdio.h>

// int main(void)
// {
//     int a[] = {-5, 3, 2, 1, -1, 0};
//     int b[6] = {0};
//     int len_a = 6;
//     int len_b = 0;

//     push(a, &len_a, b, &len_b);

//     printf("\nAfter push:\n");
//     printf("Stack A: ");
//     for (int i = 0; i < len_a; i++) printf("%d ", a[i]);
//     printf("\nStack B: ");
//     for (int i = 0; i < len_b; i++) printf("%d ", b[i]);
//     printf("\n");
//     return (0);
// }

int	get_max_bits(int *tab, int len)
{
	int	max;
	int	bits;
	int	i;

	i = 0;
	max = tab[0];
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	if (max < 0)
		max *= -1;
	bits = 0;
	while (max > 0)
	{
		max = max / 2;
		bits++;
	}
	return (bits);
}

void	radix_sort(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	int	min;
	int	i;
	int	max_bits;
	int	bit_position;
	int	size;

	// Trouver la valeur minimale dans stack_a
	min = stack_a[0];
	i = 1;
	while (i < *len_a)
	{
		if (stack_a[i] < min)
			min = stack_a[i];
		i++;
	}
	//soustraire le minimum pour rendre les nums positi
	i = 0;
	while (i < *len_a)
	{
		stack_a[i] -= min;
		i++;
	}
	// Initialiser bits à 0 dans get_max_bits
	max_bits = get_max_bits(stack_a, *len_a);
	bit_position = 0;
	while (bit_position < max_bits)
	{
		size = *len_a;
		i = 0;
		while (i < size)
		{
			if ((stack_a[0] >> bit_position) & 1)
				ra(stack_a, *len_a);
			else
				pb(stack_a, len_a, stack_b, len_b);
			i++;
		}
		// Remettre les éléments de B dans A
		while (*len_b > 0)
			pa(stack_b, len_b, stack_a, len_a);
		bit_position++;
	}
	// Maintenant je remet ls valeur originales
	i = 0;
	while (i < *len_a)
	{
		stack_a[i] += min;
		i++;
	}
}

#include <stdio.h>

int	main(int ac, char ** av)
{
	int	stack_a[500];
	int	stack_b[500];
	int	len_a;
	int	len_b;
	int i;
	
	
	if (ac < 2)
		return(0);
	i = 0;
	len_a = ac - 1;
	len_b = 0;
	while(i < ac)
	{
		stack_a[i] = ft_atoi(av[i+1]);
		i++;
	}
	
	ft_printf("Before sorting:\n");
	for (int i = 0; i < len_a; i++)
		ft_printf("%d ", stack_a[i]);
	ft_printf("\n");
	
	radix_sort(stack_a, stack_b, &len_a, &len_b);
	
	ft_printf("\nAfter sorting:\n");
	for (int i = 0; i < len_a; i++)
		ft_printf("%d ", stack_a[i]);
	ft_printf("\n");
	ft_printf("len_a: %d, len_b: %d\n", len_a, len_b);
	return (0);
}


