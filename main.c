
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node *a;
	t_stack_node *b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		av = av + 1;
	// int i = 0;
	// write(1, "stack splited\n", 14);
	// while(av[i] != 0)
	// {
	// 	printf("%s\n", av[i]);
	// 	i++;
	// }
	stack_init(&a, av, ac == 2);
	// t_stack_node *temp = a;
	// printf("stack builded !");
	// while(temp)
	// {
	// 	printf("%d\n", temp->value);
	// 	temp  = temp->next;
	// }
	if (!stack_sorted(a))
	{
		
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			three_sort(&a);
		else
			push_swap(&a, &b);
	}
	// printf("stack sorted !\n");
	// t_stack_node *tempo = a;
	// while(tempo)
	// {
	// 	printf("%d ", tempo->value);
	// 	tempo  = tempo->next;
	// }
	free_stack(&a);
}