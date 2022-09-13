#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h> 
# include "libft/libft.h"

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stacks;

//push_swap
void	ft_push_swap(int argc, char **argv);
int		sort(t_stacks *stack, int size);
void	init_stack(t_stacks *stack, int size);
//side_func
int		total_numb(char **argv);
int		char_to_int(char *str, int *stack);
void	error_msg(int *stack);
void	no_repeat(int *arr, int size);
//small_arr
int		sorted_a(int *stack, int size);
int		sorted_b(int *stack, int size);
void	sort_small_a(t_stacks *s);
int		sort_small_b(t_stacks *s, int b_len);
void	quicksort_3(t_stacks *stack, int len);
//big_arr
int		sort_big_a(t_stacks *stack, int len, int cnt);
int		sort_big_b(t_stacks *stack, int len, int cnt);
int		middle_numb(int *middle, int *stack, int size);
void	long_sort(int *long_stack, int size);
int		push(t_stacks *stack, int len, int operation);
//op
void	sa_op(t_stacks *stack);
void	sb_op(t_stacks *stack);
void	ss_op(t_stacks *stack);
void	pa_op(t_stacks *stack);
void	pb_op(t_stacks *stack);
void	ra_op(t_stacks *stack);
void	rb_op(t_stacks *stack);
void	rr_op(t_stacks *stack);
void	rra_op(t_stacks *stack);
void	rrb_op(t_stacks *stack);
void	rrr_op(t_stacks *stack);

#endif
