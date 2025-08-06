SRCS_CLIENT	= client.c \
		  client_bonus.c

SRCS_SERVER	= server.c

HEADER_CLIENT	= inc/client.h

OBJS_CLIENT	= ${addprefix srcs/, ${SRCS_CLIENT:.c=.o}}

OBJS_SERVER	= ${addprefix srcs/, ${SRCS_SERVER:.c=.o}}

NAME_CLIENT	= client

NAME_SERVER	= server

CC		= gcc -Wall -Wextra -Werror

RM		= rm -f

LIBFT		= inc/libft/libft.a

PATH_LIBFT	= -C inc/libft

PRINTF		= inc/ft_printf/libftprintf.a

PATH_PRINTF	= -C inc/ft_printf

.c.o:
		${CC} -c $< -o ${<:.c=.o}

all:		${NAME_CLIENT} ${NAME_SERVER}

${NAME_CLIENT}:	${OBJS_CLIENT}
		${MAKE} ${PATH_LIBFT}
		${MAKE} ${PATH_PRINTF}
		${CC} ${HEADER_CLIENT} ${OBJS_CLIENT} ${LIBFT} ${PRINTF} -o ${NAME_CLIENT}

${NAME_SERVER}:	${OBJS_SERVER}
		${MAKE} ${PATH_LIBFT}
		${MAKE} ${PATH_PRINTF}
		${CC} ${OBJS_SERVER} ${LIBFT} ${PRINTF} -o ${NAME_SERVER}

clean:
		${RM} ${OBJS_CLIENT} ${OBJS_SERVER}
		${MAKE} clean ${PATH_LIBFT}
		${MAKE} clean ${PATH_PRINTF}

fclean:		clean
		${RM} ${NAME_CLIENT} ${NAME_SERVER}
		${MAKE} fclean ${PATH_LIBFT}
		${MAKE} fclean ${PATH_PRINTF}

re:		fclean all

.PHONY:		all clean fclean re
