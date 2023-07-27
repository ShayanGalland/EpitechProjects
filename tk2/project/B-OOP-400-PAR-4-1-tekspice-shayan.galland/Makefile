##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## FINALLY
##

NAME	=	nanotekspice

SRC	=	src/AComponent.cpp 			\
		src/Circuit.cpp 			\
		src/main.cpp		 		\
		src/IComponent.cpp 			\
		src/Command.cpp 			\
		src/Configuration.cpp 		\
		src/Component/true.cpp 		\
		src/Component/false.cpp 	\
		src/Component/input.cpp 	\
		src/Component/output.cpp 	\
		src/Component/clock.cpp 	\
		src/Component/and.cpp 		\
		src/Component/or.cpp 		\
		src/Component/xor.cpp 		\
		src/Component/not.cpp 		\
		src/Component/4001.cpp 		\
		src/Component/4081.cpp 		\
		src/Component/4030.cpp 		\
		src/Component/4071.cpp 		\
		src/Component/4011.cpp 		\
		src/Component/4069.cpp 		\



OBJ	=	$(SRC:.cpp=.o)

CFLAGS	=	-std=c++2a -Wall -Wextra -Werror -g

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CFLAGS)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all