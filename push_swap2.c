#include <stdio.h>
#include "push_swap.h"

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
	ft_printf("pa\n");
}

void	pb(int *tab1, int *len1, int *tab2, int *len2)
{
	push(tab1, len1, tab2, len2);
	ft_printf("pb\n");
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
	ft_printf("rb\n");
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
	// Soustraire le minimum pour rendre les nums positifs
	i = 0;
	while (i < *len_a)
	{
		stack_a[i] -= min;
		i++;
	}
	// Obtenir le nombre de bits nécessaires
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
	// Maintenant je remets les valeurs originales
	i = 0;
	while (i < *len_a)
	{
		stack_a[i] += min;
		i++;
	}
}

int ft_tab_len(char **str)
{
    int count;

    count = 0;

    if (!str)
        return (0);
    while(str[count])
        count++;
    return (count);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
int main(int ac, char **av)
{
    int *stack_a = NULL;
    int *stack_b = NULL;
    char **str;
    int len_a;
    int len_b = 0;
    int i;

    if (ac < 2)
        return (0);

    if (ac == 2)
    {
        str = ft_split(av[1], ' ');
        if (!str)
            return (1);  // Handle allocation failure

        len_a = ft_tab_len(str);
        if (len_a == 0)
        {
            free_split(str);
            return (1);  // No numbers provided
        }

        stack_a = malloc(len_a * sizeof(int));
        stack_b = malloc(len_a * sizeof(int));
        if (!stack_a || !stack_b)
        {
            free_split(str);
            free(stack_a);
            free(stack_b);
            return (1);  // Handle allocation failure
        }

        i = 0;
        while (i < len_a)
        {
            stack_a[i] = ft_atoi(str[i]);
            i++;
        }
        free_split(str);  // Free memory allocated by ft_split
    }
    else
    {
        len_a = ac - 1;
        stack_a = malloc(len_a * sizeof(int));
        stack_b = malloc(len_a * sizeof(int));
        if (!stack_a || !stack_b)
        {
            free(stack_a);
            free(stack_b);
            return (1);  // Handle allocation failure
        }

        i = 0;
        while (i < len_a)
        {
            stack_a[i] = ft_atoi(av[i + 1]);
            i++;
        }
    }

    printf("Before sorting:\n");
    for (i = 0; i < len_a; i++)
        printf("%d ", stack_a[i]);
    printf("\n");

    radix_sort(stack_a, stack_b, &len_a, &len_b);

    printf("\nAfter sorting:\n");
    for (i = 0; i < len_a; i++)
        printf("%d ", stack_a[i]);
    printf("\n");

    free(stack_a);
    free(stack_b);
    return (0);
}