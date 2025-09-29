NAME = push_swap

CC = gcc

CFLAGS = -Werror -Wall -Wextra 

RM = rm -rf

SRCS = 	main.c\
		mainhelper.c\
		helper2.c\
		helper3.c\
		pushswapoperations.c\
		rroperations.c\
		libft/libft.a\
		
$(NAME) :
	make -C libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all
