SRCS = ft_printf.c ft_putchar.c ft_puthex.c ft_putid.c \
		ft_putptr.c ft_putstr.c ft_putun.c

LIBFT = ./libft/libft.a
LIBFTDIR = ./libft
SRC = ./src
BIN = bin
OBJS = ${SRCS:%.c=${BIN}/%.o}
NAME = libftprintf.a
LIBC = ar rcs
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
CP = cp

all: ${NAME}

${NAME}: ${BIN} ${LIBFT} ${OBJS}
	${CP} ${LIBFT} ${NAME}
	${LIBC} ${NAME} ${OBJS}

$(LIBFT):	$(LIBFTDIR)
			$(MAKE) -C $(LIBFTDIR)

${BIN}/%.o: ${SRC}/%.c
	${CC} ${CFLAGS} -c $< -o $@ 

${BIN}:
	@mkdir -p ${BIN}

clean:
	${MAKE} clean -C ${LIBFTDIR}
	${RM} ${BIN} ${OBJS}

fclean: clean
	${MAKE} fclean -C ${LIBFTDIR}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re