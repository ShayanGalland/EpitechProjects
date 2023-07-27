##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC	=	src/main.c	\
		src/init.c	\
		src/utils.c	\
		src/lemin.c	\
		src/count_data.c	\
		src/init_rooms.c	\
		src/src_graph/add_edge.c	\
		src/src_graph/add_node_list.c	\
		src/src_graph/creat_new_graph.c	\
		src/src_graph/display_graph.c	\
		src/src_graph/ecrase_graph.c	\
		src/src_graph/is_empty_graph.c	\
		src/error.c						\
		src/error_rooms.c

OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

LIB	=	-L./lib/my -lmy

CPPFLAGS	=	-I./include

CFLAGS+= -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(LIB)

clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean: clean
	make fclean -C lib/my
	rm -f $(NAME)

re:	fclean all

debug: CFLAGS += -g
debug: re

.PHONY: all clean fclean re tests_run debug
