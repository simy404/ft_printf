NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = 	ft_printf.c		\
		ft_format_utils.c 	\
		ft_print_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY : all clean fclean re
