##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC	=	my_compute_square_root.c\
		my_find_prime_sup.c	\
		my_getnbr.c		\
		my_isneg.c		\
		my_is_prime.c		\
		my_putchar.c		\
		my_putnbr.c		\
		my_putstr.c		\
		my_put_octal.c	\
		my_put_maj_s_tr.c	\
		my_printf.c		\
		my_revstr.c		\
		my_showmem.c		\
		my_showstr.c		\
		my_sort_int_array.c	\
		my_strcapitalize.c	\
		my_strcat.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c		\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c		\
		my_strlowcase.c		\
		my_strncat.c		\
		my_strncmp.c		\
		my_strncpy.c		\
		my_strstr.c		\
		my_strupcase.c		\
		my_swap.c		\
		my_str_to_word_array.c	\
		my_split.c		\
		count_word.c		\
		display_tab.c		\
		my_tablen.c		\
		my_free.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
		ar -rc $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
