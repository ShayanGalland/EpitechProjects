##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC			=	./sources/print_b.c					\
				./sources/print_d.c					\
				./sources/printf.c					\
				./sources/print_o.c					\
				./sources/print_s.c					\
				./sources/print_S.c					\
				./sources/print_x.c					\
				./sources/print_xx.c					\
				./sources/my_putchar.c    			\
				./sources/my_putnbr.c					\
				./sources/printfbis.c     			\
				./sources/my_putstr.c					\
				./sources/my_compute_power_it.c		\
				./sources/print_x_bis.c     			\
				./sources/print_xx_bis.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-Wall -Wextra

all:		$(NAME)
		rm sources/*.o

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
