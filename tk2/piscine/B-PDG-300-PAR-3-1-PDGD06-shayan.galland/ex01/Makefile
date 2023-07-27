##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## FINALLY
##

NAME	=	MyCat

SRC	=	MyCat.cpp 	\

OBJ	=	$(SRC:.cpp=.o)

CFLAGS	=	-std=c++20 -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CFLAGS)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all