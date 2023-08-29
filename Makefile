CFLAGS = -Wall -Werror -Wextra

NAME = bsq

SCR =              //NAME OF FILE TO COMPILE

$(NAME):
	cc $(CFLAGS) $(SCR) -o $(NAME)

clean:

fclean: clean
	rm $(NAME)
