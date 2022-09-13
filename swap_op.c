#include "push_swap.h"

void	sa_op(t_stacks *stack)
{
	int	temp;

	if (stack->size_a > 1)
	{
		temp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = temp;
		ft_printf("sa\n");
	}
}

void	sb_op(t_stacks *stack)
{
	int	temp;

	if (stack->size_b > 1)
	{
		temp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = temp;
		ft_printf("sb\n");
	}
}

void	ss_op(t_stacks *stack)
{
	int	temp;

	if (stack->size_a > 1 && stack->size_b > 1)
	{
		temp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = temp;
		temp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = temp;
		ft_printf("ss\n");
	}
}
