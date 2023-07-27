##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC	=	sources/boat_pos_on_map.c  				\
		sources/boat_pos.c 						\
		sources/con_pid.c 						\
		sources/count_hit_on_map.c 				\
		sources/create_bits_mask.c 				\
		sources/create_map.c 					\
		sources/extract_n_bits.c 				\
		sources/free_map.c						\
		sources/game_make.c 					\
		sources/hit_on_map.c 					\
		sources/isFinish.c 						\
		sources/main.c 							\
		sources/my_getnbr.c 					\
		sources/my_putchar.c 					\
		sources/my_putnbr.c 					\
		sources/my_strcmp.c 					\
		sources/my_strlen.c 					\
		sources/number_to_signal.c 				\
		sources/print_man.c 					\
		sources/print_map.c 					\
		sources/print_shoot_result.c			\
		sources/re_game.c 						\
		sources/read_boat_position.c			\
		sources/read_player_input.c 			\
		sources/SendConfirmationConnection.c	\
		sources/SendEnnemyConnected.c 			\
		sources/SendShoot.c 					\
		sources/Shoot.c 						\
		sources/SendShootResult.c 				\
		sources/signal_handler.c 				\
		sources/WaitForBitsWritten.c 			\
		sources/WaitForConfirmationConnection.c \
		sources/WaitForEnnemyConnected.c 		\
		sources/WaitForShoot.c  				\
		sources/WaitForShootResult.c 			\
		sources/WaitShoot.c

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

CFLAGS	=	-Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OBJ)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
