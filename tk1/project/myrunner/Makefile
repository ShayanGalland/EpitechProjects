##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC	=	sources/main.c \
		sources/create_render_window.c \
		sources/event_close.c	\
		sources/help.c	\
		sources/strcmp.c	\
		sources/my_strlen.c	\
		sources/game_stat.c	\
		sources/parallax.c \
		sources/set_pos.c 	\
		sources/back_stat.c \
		sources/create_sprite.c \
		sources/start_point.c	\
		sources/hero.c	\
		sources/create_and_anim.c	\
		sources/enemies.c	\
		sources/draw_en.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

CFLAGS	=	-Wall -Wextra

LDFLAGS = 	-lm -lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
