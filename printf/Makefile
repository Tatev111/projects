SRCS =  $(shell find "." -name "*.c")
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
CC	= gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
AR = ar csr

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
$(NAME) : ${OBJS}
	${AR} libftprintf.a ${OBJS}
all: ${NAME}
clean: 
		${RM} ${OBJS}
fclean: clean
		${RM} ${NAME}
re: fclean all
