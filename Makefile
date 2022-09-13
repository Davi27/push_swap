NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -fsanitize=address -g
FILES	= push_swap side_func small_arr big_arr \
		reverse_rotate_op rotate_op swap_op push_op
		
SRC		= $(addsuffix .c, $(FILES))
OBJ		= $(addsuffix .o, $(FILES))


all:		$(NAME)


$(NAME):	$(OBJ)
			@make -C libft
			@cp libft/libft.a .
			@$(CC) $(CFLAGS) $(SRC) libft.a -o $(NAME)


$(OBJ):		$(SRC) push_swap.h
			@$(CC) $(CFLAGS) -c $< -o $@


clean:
			@make clean -C libft
			@rm -f *.o


fclean:		clean
			@rm -f $(NAME)
			@rm -f libft.a
			@rm -f libft/libft.a
			

re:			fclean all


.PHONY:		all clean fclean re
