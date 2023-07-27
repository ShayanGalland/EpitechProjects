##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC			=	src/map_utils.c					\
				src/help.c						\
				src/create_block.c 				\
				src/utils.c 					\
				src/map_param.c 				\
				src/game_bloc_params.c 			\
				src/bloc_mod.c 					\
				src/game_gestion.c 				\

OBJ			=	$(SRC:.c=.o)

NAME		=	tetris

CPPFLAGS	=	-I./Include

LDFLAGS		=	-L./lib/my -lmy

CFLAGS 		=	-Wall -Wextra

FLAGS 		=	$(CFLAGS) $(LDFLAGS) $(CPPFLAGS) -lncurses

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C lib/my/
			$(CC) -o $(NAME) $(OBJ) $(FLAGS)

debug:		CFLAGS += -g3
debug:		re

clean:
			clear
			$(RM) -f $(OBJ)
			$(RM) -f vgcore.*

fclean:		clean
			make fclean -C lib/my
			$(RM) -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re debug
