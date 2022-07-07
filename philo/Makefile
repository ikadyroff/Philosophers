NAME	=	philo

SRCS 	=	philo.c actions.c init.c secondary.c secondary_2.c

HEADER	=	philo.h

OBJ		=	$(SRCS:%.c=%.o)

CC		=	gcc

FLAGS	= -Wall -Wextra -Werror -fsanitize=thread

RM		=	rm -rf

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
				$(CC) $(FLAGS) $(OBJ) -o $(NAME)
%.o		:	%.c $(HEADER)
				$(CC) $(FLAGS) -c $< -o $@

clean	:
			@$(RM) $(OBJ)

fclean	:	clean
				@$(RM) $(NAME)