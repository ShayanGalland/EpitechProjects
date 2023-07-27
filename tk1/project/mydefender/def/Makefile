##
## EPITECH PROJECT, 2021
## make
## File description:
## make
##

SRC				=	sources/menu/main_menu_state.c				\
					sources/menu/main_setting_state.c			\
					sources/menu/main_rules_state.c				\
					sources/menu/my_defender.c					\
					sources/menu/start_state.c					\
					sources/menu/ui.c							\
					sources/menu/ui_button.c					\
					sources/game/my_lib_function/my_putstr.c 	\
					sources/game/my_lib_function/my_put_nbr.c	\
					sources/game/my_lib_function/my_strcmp.c	\
					sources/game/my_lib_function/my_putchar.c	\
					sources/game/my_lib_function/my_strlen.c	\
					sources/game/my_defender.c					\
					sources/game/prt.c							\
					sources/game/move_turets.c 					\
					sources/game/map_one.c						\
					sources/game/set_pos.c 						\
					sources/game/platform_one.c 				\
					sources/game/text.c 						\
					sources/game/pos_turrets.c					\
					sources/game/move_enemies.c					\
					sources/game/tur_params.c					\
					sources/game/animate_en.c					\
					sources/game/struct_en.c					\
					sources/game/struct_map.c					\
					sources/game/struct_plat.c					\
					sources/game/struct_tow.c					\
					sources/game/struct_bul.c 					\
					sources/game/make_tour_od.c 				\
					sources/game/make_tour_tq.c 				\
					sources/game/main.c 						\

OBJ				=	$(SRC:.c=.o)

NAME_BIN			=	my_defender

CPPFLAGS		+=	-Iinclude

CFLAGS			=	-g

all:				$(NAME_BIN)

$(NAME_BIN):			$(OBJ)
	gcc -o $(NAME_BIN) -Wall -Wextra $(OBJ) -lcsfml-graphics	\
-lcsfml-system -lcsfml-audio -lm	 -lcsfml-window -g3

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME_BIN)

re:				fclean all
