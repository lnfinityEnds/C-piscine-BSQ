CFLAGS = -Wall -Werror -Wextra

NAME = Bsq

SCR =              //NAME OF FILE TO COMPILE

$(NAME):
	cc $(CFLAGS) $(SCR) -o $(NAME)

clean:

fclean: clean
	rm $(NAME)
