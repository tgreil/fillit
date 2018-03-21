RM		=	rm -rf

NAME	=	fillit

CFLAGS	+=	-Wall -Wextra -Werror

CFLAGS	+=	-Iincludes

SRCS	=	fillit.c			\
			map.c				\
			pieces.c			\
			map_print.c			\
			utils.c				\
			parser.c			\
			errors_handler.c		

OBJS	=	$(addprefix srcs/, $(SRCS:.c=.o))

$(NAME):	 $(OBJS)
		gcc -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
