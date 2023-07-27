##
## EPITECH PROJECT, 2021
## Task
## File description:
## task01
##

SRC	=	my_compute_power_rec.c		\
		my_compute_square_root.c	\
		my_getnbr.c			\
		my_isneg.c			\
		my_is_prime.c			\
		my_putchar.c			\
		my_put_nbr.c			\
		my_putstr.c			\
		my_revstr.c			\
		my_strcat.c			\
		my_strcpy.c			\
		my_strlen.c			\
		my_swap.c			\
		my_strdup.c			\
		my_string_to_int.c	\
		my_int_to_string.c	\
		my_str_to_word_array.c	\
		my_str_isnum.c	\
		my_strcmp.c	\
		my_strncmp.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re:	fclean all
