SRCS = ft_printf.c ft_putchar.c ft_puthex.c ft_putid.c \
		ft_putptr.c ft_putstr.c ft_putun.c

SRC = ./src
BIN = bin
OBJS = ${SRCS:%.c=${BIN}/%.o}
NAME = libftprintf.a
LIBC = ar rcs
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${BIN} ${OBJS}
	${LIBC} ${NAME} ${OBJS}

${BIN}/%.o: ${SRC}/%.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@ 

${BIN}:
	@mkdir -p ${BIN}

clean:
	${RM} ${BIN} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re