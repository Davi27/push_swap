#include "push_swap.h"

int	sort_big_a(t_stacks *stack, int len, int cnt)
{
	int	middle;
	int	numbers;

	if (sorted_a(stack->a, len))
		return (1);
	numbers = len;
	if (len <= 3)
	{
		quicksort_3(stack, len);
		return (1);
	}
	if (!cnt && !middle_numb(&middle, stack->a, len))
		return (0);
	while (len != numbers / 2 + numbers % 2)
	{
		if (stack->a[0] < middle && (len--))
			pb_op(stack);
		else if (++cnt)
			ra_op(stack);
	}
	while (numbers / 2 + numbers % 2 != stack->size_a && cnt--)
		rra_op(stack);
	return (sort_big_a(stack, numbers / 2 + numbers % 2, 0)
		&& sort_big_b(stack, numbers / 2, 0));
	return (1);
}

int	sort_big_b(t_stacks *stack, int len, int cnt)
{
	int	middle;
	int	numbers;

	if (!cnt && sorted_b(stack->b, len))
		while (len--)
			pa_op(stack);
	if (len <= 3)
	{
		sort_small_b(stack, len);
		return (1);
	}
	numbers = len;
	if (!middle_numb(&middle, stack->b, len))
		return (0);
	while (len != numbers / 2)
	{
		if (stack->b[0] >= middle && len--)
			pa_op(stack);
		else if (++cnt)
			rb_op(stack);
	}
	while (numbers / 2 != stack->size_b && cnt--)
		rrb_op(stack);
	return (sort_big_a(stack, numbers / 2 + numbers % 2, 0)
		&& sort_big_b(stack, numbers / 2, 0));
}

int	middle_numb(int *middle, int *stack, int size)
{
	int	*long_stack;
	int	i;

	long_stack = (int *)malloc(size * sizeof(int));
	if (!long_stack)
		return (0);
	i = 0;
	while (i < size)
	{
		long_stack[i] = stack[i];
		i++;
	}
	long_sort(long_stack, size);
	*middle = long_stack[size / 2];
	free(long_stack);
	return (1);
}

void	long_sort(int *long_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (long_stack[i] > long_stack[j])
			{
				tmp = long_stack[i];
				long_stack[i] = long_stack[j];
				long_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	push(t_stacks *stack, int len, int operation)
{
	if (operation == 0)
		pb_op(stack);
	else
		pa_op(stack);
	len--;
	return (len);
}
