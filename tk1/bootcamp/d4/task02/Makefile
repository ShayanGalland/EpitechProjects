##
## EPITECH PROJECT, 2021
## y
## File description:
## y
##
SRC	=	concat_parameters.c

OBJ	=	$(SRC:.c=.o)

NAME	=	concat_parameters

CFLAGS	=	-Wall -Wextra

GFLAGS =	-I/includes -L/lib/phoenix -lphoenix

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C ../lib/phoenix
		gcc -o $(NAME) $(CFLAGS) $(GFLAGS) $(SRC)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
