SRCS = srcs/ft_putchar.c srcs/ft_outstr.c srcs_ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

.c.o:
	${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar rc ${NAME} {OBJS}
	ranlib ${NAME}

clean: 
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fcleanall

.PHONY: all clean fclean re