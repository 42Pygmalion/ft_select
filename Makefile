NAME = ft_select

SRC = ft_select.c

OBJ = $(SRC:.c=.o) 

SRH = ft_select.h 

all: $(NAME)

$(NAME):
	@(cd libft && $(MAKE))
	gcc -Wall -Wextra -Werror -I libft/ -c $(SRC)
	gcc -o $(NAME) $(OBJ) -lncurses -L libft/ -lft

clean:
	@(cd libft && $(MAKE) $@)
	/bin/rm -f $(OBJ)

fclean: clean
	@(cd libft && $(MAKE) $@)
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
