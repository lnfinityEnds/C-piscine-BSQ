NAME = Bsq

SRC = check_map.c find.c ft_print_map.c ft_read_file.c

CC = gcc

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

OUTPUT = bsq

all : ${SRC} ${NAME}
	
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

${NAME} : ${OBJ}
        ${CC} ${CFLAGS} -o $@

clean :
	rm -f ${NAME}

fclean : clean
	rm -f ${OBJ}

re : fclean all

.PHONY : all clean fclean re