##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c				\
		src/op.c				\
		src/error.c				\
		src/assembler.c			\
		src/utils.c				\
		src/create.c			\
		src/write_header.c		\
		src/get_data.c			\
		src/write_instruction.c	\
		src/get_index.c

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

CPPFLAGS	=	-I./include

CFLAGS	=	-Wall -Wextra

DEBUGFLAG	=	-g3

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L../lib/my -lmy

clean:
	$(RM) -f $(OBJ)

fclean:	clean
	$(RM) -r $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
