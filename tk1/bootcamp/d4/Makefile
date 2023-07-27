##
## EPITECH PROJECT, 2021
## y
## File description:
## y
##
SRC	=	*.c

OBJ	=	$(SRC:.c=.o)

NAME	=	a.out

CFLAGS	=	-Wall -Wextra

GFLAGS =	-Iincludes -Llib/phoenix -lphoenix

all:		$(NAME)

$(NAME):	$(OBJ)
       		make -C lib/phoenix
		gcc -o $(NAME) $(CFLAGS) $(GFLAGS) $(SRC)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
