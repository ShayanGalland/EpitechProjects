##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/display_file.c	\
		src/load_file.c	\
		src/load_2d_arr_from_file.c	\
		src/mem_alloc_2d_array.c	\
		src/random.c 			\
		src/init_disp.c		\
		src/my_free.c	\
		src/display_start.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	lingo

CFLAGS	=	-Wall -Wextra -g

LDFLAGS	=	-L./lib/my -lmy	

CPPFLAGS	=	-I include

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f temp_file.txt
	rm -f *.c~
	rm -f *units_tests
	rm -f *.gcda
	rm -f *.gcno
	rm -f vgcore*
	rm -f *~
	make fclean -C lib/my

fclean: clean
	rm -f $(NAME)

re:	fclean all clean
