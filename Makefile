NAME = Bsq

SRC = 

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