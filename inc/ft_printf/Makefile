SRCS	=	ft_printf.c\
			ft_types1.c\
			ft_types2.c\
			ft_types3.c

OBJS	=	${SRCS:.c=.o}

NAME	=	libftprintf.a

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
		ar rc ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
