SRCS	= prove.c read_input.c read_input2.c ft_util.c ft_free.c algo.c ft_print.c 
OBJS	= ${SRCS:.c=.o}
INCL	= includes
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= bsq

.c.o:
			${CC} ${CFLAGS} -I ${INCL} -c $< -o ${<:.c=.o}

all : 		${NAME}

${NAME} :	${OBJS}
			${CC} -o ${NAME} ${OBJS}

clean :
			rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME}

re :		fclean all

GM		=./good_maps/

GMNAMES	= 1						\
		  10					\
		  100					\
		  100big_soluce			\
		  100obst				\
		  100vide				\
		  10b					\
		  5						\
		  diagonal				\
		  example_file			\
		  full					\
		  hundredxhundred		\
		  invisible_obstacle	\
		  nb					

BM		=./bad_maps/

BMNAMES	= empty_line		\
		  just_first_line	\
		  non_ascii_char	\
		  one_empty_line	\
		  one_short_line	\
		  too_much_line		\
		  vide

GOODS	= ${addprefix ${GM},${GMNAMES}}

BADS 	=${addprefix ${BM},${BMNAMES}}

test_good:	all
			./${NAME} ${GOODS}

test_bad:	all
			./${NAME} ${BADS}

test:		all
			./${NAME} ${GOODS} ${BADS}

.PHONY: all clean fclean re ${NAME}

