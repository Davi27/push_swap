#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		argv++;
		if (argc == 2)
			argv = ft_split(*argv, ' ');
		ft_push_swap(argc, argv);
		return (0);
	}
	return (0);
}

void	ft_push_swap(int argc, char **argv)
{
	t_stacks	stack;
	int			size;
	int			i;
	int			j;

	j = 0;
	i = -1 + j;
	size = total_numb(argv);
	init_stack(&stack, size);
	while (++i < size)
		stack.a[i] = char_to_int(argv[i], stack.a);
	if (argc == 2)
	{
		while (j < size)
			free(argv[j++]);
		free(argv);
	}
	no_repeat(stack.a, size);
	sort(&stack, size);
	free(stack.a);
	free(stack.b);
}

int	sort(t_stacks *stack, int size)
{
	if (!sorted_a(stack->a, stack->size_a))
	{
		if (size == 2)
			sa_op(stack);
		else if (size == 3)
			sort_small_a(stack);
		else
			sort_big_a(stack, size, 0);
	}
	return (0);
}

void	init_stack(t_stacks *stack, int size)
{
	stack->a = malloc(size * sizeof(int));
	if (!stack->a)
		return ;
	stack->size_a = size;
	stack->b = malloc(size * sizeof(int));
	if (!stack->b)
	{
		free(stack->a);
		return ;
	}
	stack->size_b = 0;
}
