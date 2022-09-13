#include "push_swap.h"

int	sorted_a(int *stack, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (stack[i - 1] > stack[i])
			return (0);
		i++;
	}
	return (1);
}

int	sorted_b(int *stack, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (stack[i - 1] < stack[i])
			return (0);
		i++;
	}
	return (1);
}

void	sort_small_a(t_stacks *s)
{
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
	{
		sa_op(s);
		rra_op(s);
	}
	if (s->a[0] > s->a[1] && s->a[0] < s->a[2] && s->a[1] < s->a[2])
		sa_op(s);
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] < s->a[2])
		ra_op(s);
	if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] > s->a[2])
	{
		sa_op(s);
		ra_op(s);
	}
	if (s->a[0] < s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
		rra_op(s);
}

int	sort_small_b(t_stacks *s, int b_len)
{
	if (b_len == 1)
		pa_op(s);
	else if (b_len == 2)
	{
		if (s->b[0] < s->b[1])
			sb_op(s);
		while (b_len--)
			pa_op(s);
	}
	else if (b_len == 3)
	{
		while (b_len || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (b_len == 1 && s->a[0] > s->a[1])
				sa_op(s);
			else if (b_len == 1 || (b_len >= 2 && s->b[0] > s->b[1])
				|| (b_len == 3 && s->b[0] > s->b[2]))
				b_len = push(s, b_len, 1);
			else
				sb_op(s);
		}
	}
	return (0);
}

void	quicksort_3(t_stacks *stack, int len)
{
	if (len == 3 && stack->size_a == 3)
		sort_small_a(stack);
	else if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa_op(stack);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				sa_op(stack);
			else if (len == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				len = push(stack, len, 0);
			else if (stack->a[0] > stack->a[1])
				sa_op(stack);
			else if (len++)
				pa_op(stack);
		}
	}
}
