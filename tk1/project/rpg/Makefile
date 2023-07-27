##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c						\
		src/game.c						\
		src/init.c						\
		src/create_sprite.c 			\
		src/set_sprite_state_other.c	\
		src/set_sprite_state.c			\
		src/animation.c 				\
		src/display.c					\
		src/menu.c						\
		src/get_data.c					\
		src/math_entity.c				\
		src/math_utils.c				\
		src/map_colision.c 				\
		src/init_colision.c 			\
		src/menu_settings.c				\
		src/menu_button.c				\
		src/shoot.c 					\
		src/move.c 						\
		src/utils.c 					\
		src/create_texte.c 				\
		src/pause.c						\
		src/pause_button.c 				\
		src/attack.c 					\
		src/spawning_zone.c 			\
		src/init_values.c 				\
		src/anim_ghost.c				\
		src/init_display.c 				\
		src/menu_interact.c 			\
		src/ghost_attack.c 				\
		src/ghost_mv.c 					\
		src/manage_map.c 				\
		src/map_switch.c 				\
		src/hero_interaction.c 			\
		src/inventory.c					\
		src/events.c					\
		src/items/items.c				\
		src/tuto.c						\
		src/hint.c						\
		src/music.c						\
		src/level.c						\
		src/boss.c 						\
		src/boss_fight.c 				\

OBJ	=	$(SRC:.c=.o)

NAME    =	my_rpg

SFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lm

CPPFLAGS	=	-I./include

CFLAGS	=	-Wall -Wextra

all:    $(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my
	$(CC) -o $(NAME) $(OBJ) -L./lib/my -lmy -g3 $(SFML)

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)
	$(MAKE) fclean -C lib/my

re:     fclean all

.PHONY: all clean fclean re
