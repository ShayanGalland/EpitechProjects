##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## FINALLY
##

NAME	= MyGKrellm

CXX		= g++

RM		= rm -f

SRC	=	proc.cpp	\
		graphical.cpp 	\
		main.cpp		\
		ncurse.cpp 		\


CXXFLAGS = -Wall -Wextra -Werror -lncurses -lsfml-graphics -lsfml-window -lsfml-system

OBJ	=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME):
	$(CXX) $(SRC) -o $(NAME) $(CXXFLAGS)

clean:
		clear
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:			fclean all

.PHONY:
	all clean fclean re
