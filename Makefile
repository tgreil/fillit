RM		=	rm -rf

NAME	=	fillit

CFLAGS	+=	-Wall -Wextra -Werror -O3

CFLAGS	+=	-I.

SRCS	=	fillit.c			\
			map.c				\
			pieces.c			\
			map_print.c			\
			map_calc.c			\
			utils.c				\
			parser.c			\
			errors_handler.c

OBJS	=	$(SRCS:.c=.o)

$(NAME):	 $(OBJS)
		gcc -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
