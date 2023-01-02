SRCS = ${wildcard srcs/*.c}

OBJS = ${SRCS:.c=.o}

INC = -I inc/ -I libft
LIBFTPATH = -L libft -lft
LIBS = ${INC} ${LIBFTPATH}

EXEC = push_swap
CC = cc
CFLAGS =# -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}

${EXEC}:	${OBJS} 
		+$(MAKE) -C libft
		gcc -o ${EXEC} ${CFLAGS} ${OBJS} ${LIBS}

all:	${EXEC}

run: all
	rm -f ${OBJS} {EXEC}
	./push_swap 4 42 8 23 15 16

clean:	
		+$(MAKE) -C libft clean
		rm -f ${OBJS} 

fclean:	clean;
		+$(MAKE) -C libft fclean
		rm -f ${EXEC}

re:	fclean all

norminette:
		norminette srcs/