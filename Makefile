SRCS = ${wildcard srcs/*.c}

OBJS = ${SRCS:.c=.o}

INC = -I inc/ -I libft
LIBFTPATH = -L libft -lft
LIBS = ${INC} ${LIBFTPATH}

# NUMBERS = 3 2 1
NUMBERS = 4 42 8 23 15 16
# NUMBERS = 1

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
	./push_swap ${NUMBERS}
	./push_swap ${NUMBERS} | ./checker_linux ${NUMBERS}

run_macos: all
	rm -f ${OBJS} {EXEC}
	./push_swap ${NUMBERS}
	./push_swap ${NUMBERS} | ./checker_macos ${NUMBERS}

clean:	
		+$(MAKE) -C libft clean
		rm -f ${OBJS} 

fclean:	clean;
		+$(MAKE) -C libft fclean
		rm -f ${EXEC}

re:	fclean all

norminette:
		norminette srcs/