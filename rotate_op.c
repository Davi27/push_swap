#include "push_swap.h"

void	ra_op(t_stacks *stack)
{
	int	temp;
	int	i;

	if (stack->size_a > 1)
	{
		i = 0;
		temp = stack->a[i];
		while (i < stack->size_a - 1)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->a[i] = temp;
		ft_printf("ra\n");
	}
}

void	rb_op(t_stacks *stack)
{
	int	temp;
	int	i;

	if (stack->size_b > 1)
	{
		i = 0;
		temp = stack->b[i];
		while (i < stack->size_b - 1)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->b[i] = temp;
		ft_printf("rb\n");
	}
}

void	rr_op(t_stacks *stack)
{
	int	temp;
	int	i;

	if (stack->size_a > 1 && stack->size_b > 1)
	{
		i = 0;
		temp = stack->a[i];
		while (i < stack->size_a - 1)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->a[i] = temp;
		i = 0;
		temp = stack->b[i];
		while (i < stack->size_b - 1)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->b[i] = temp;
		ft_printf("rr\n");
	}
}
