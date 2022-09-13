#include "push_swap.h"

int	total_numb(char **argv)
{
	int	i;

	i = 0;
	while (*argv)
	{
		argv++;
		i++;
	}
	return (i);
}

int	char_to_int(char *str, int *stack)
{
	unsigned int		i;
	unsigned long int	numb;
	int					neg;

	numb = 0;
	i = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = -1;
	if ((str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_msg(stack);
		numb = (str[i] - '0') + (numb * 10);
		i++;
	}
	if ((numb > 2147483648 && neg == -1) || (numb > 2147483647 && neg == 1))
		error_msg(stack);
	return (numb * neg);
}

void	error_msg(int *stack)
{
	free(stack);
	printf("Error\n");
	exit (1);
}

void	no_repeat(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (arr[i] == arr[j])
				error_msg(arr);
			j++;
		}
		i++;
		j = i + 1;
	}
}
