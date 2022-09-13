#include "push_swap.h"

void	rra_op(t_stacks *stack)
{
	int	temp;
	int	i;

	if (stack->size_a > 1)
	{
		i = stack->size_a;
		temp = stack->a[i - 1];
		while (--i)
			stack->a[i] = stack->a[i - 1];
		stack->a[i] = temp;
		ft_printf("rra\n");
	}
}

void	rrb_op(t_stacks *stack)
{
	int	temp;
	int	i;

	if (stack->size_b > 1)
	{
		i = stack->size_b;
		temp = stack->b[i - 1];
		while (--i)
			stack->b[i] = stack->b[i - 1];
		stack->b[i] = temp;
		ft_printf("rrb\n");
	}
}

void	rrr_op(t_stacks *stack)
{
	int	temp;
	int	i;

	if (stack->size_a > 1 && stack->size_b > 1)
	{
		i = stack->size_a;
		temp = stack->a[i - 1];
		while (--i)
			stack->a[i] = stack->a[i - 1];
		stack->a[i] = temp;
		i = stack->size_b;
		temp = stack->b[i - 1];
		while (--i)
			stack->b[i] = stack->b[i - 1];
		stack->b[i] = temp;
		ft_printf("rrr\n");
	}
}
