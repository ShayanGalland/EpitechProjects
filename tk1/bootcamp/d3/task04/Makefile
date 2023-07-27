##
## EPITECH PROJECT, 2021
## y
## File description:
## y
##
SRC	=	show_params.c

OBJ	=	$(SRC:.c=.o)

NAME	=	show_params

CFLAGS	=	-Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(SRC)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
