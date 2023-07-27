##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC	=	sources/find_max_square.c			\
		sources/init_matrix.c				\
		sources/main.c					\
		sources/min_three.c				\
		sources/my_atoi.c				\
		sources/my_putchar.c				\
                sources/my_strlen.c				\
                sources/print_map.c				\
                sources/print_square_in_map.c			\
                sources/read_line.c				\
		sources/read_lines_count.c			\
                sources/read_map.c				\
                sources/read_map_file.c				\
                sources/read_map_line.c				\
                sources/reset_buffer.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
