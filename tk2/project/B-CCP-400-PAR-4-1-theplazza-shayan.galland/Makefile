##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## FINALLY
##

NAME	=	plazza

SRC	=	src/main.cpp		\
		src/reception.cpp 	\
		src/pizza.cpp 		\
		src/cook.cpp 		\
		src/kitchen.cpp 	\
		src/ingredient.cpp 	\





OBJ	=	$(SRC:.cpp=.o)

CFLAGS	=	-std=c++2a -Wall -Wextra -Werror -g -lpthread -lrt

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CFLAGS)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all