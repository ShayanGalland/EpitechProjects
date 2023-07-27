/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** my_defender.h
*/

#include "my_struct.h"

#ifndef _MY_DEFENDER_H_
    #define _MY_DEFENDER_H_
static int const volatile SUCCESS = 0;
static int const volatile EXIT_FAILLER = -1;
static int const volatile ERROR = 84;

int my_defender(map_t *map_t, sfWindow *window);
void free_all(game_t *d);
sfSprite *create_sprite(sfTexture *texture);
void analyse_events(game_t *d, map_t *map_t);
void init_menu(game_t *g);
void maps(game_t *d, map_t *map_t, float elapsed);
void draw_menu(game_t *g);
sfVector2f start_point(float a, float b);
void prt_mp(game_t *d, map_t *map_t);
void prt_tur(game_t *d, map_t *map_t);
void game(game_t *d, map_t *map_t);
void mv_turs(game_t *d, map_t *map_t);
void map_one(game_t *d, map_t *map_t, float elapsed);
void move_enemies_o(map_t *map_t, float elapsed, sfSprite *enemie, int speed, int type, int nb);
void render_plat(game_t *d, map_t *map_t, int i);
void move_enemies_d(map_t *map_t, float elapsed);
void move_enemies_t(map_t *map_t, float elapsed);
int gameplay(game_t *d, map_t *map_t, float elapsed);
void maps(game_t *d, map_t *map_t, float elapsed);
void set_all_pos(map_t *map_t, game_t *d);
unsigned int generate_random_number(int min, int max);
void prt_price(sfRenderWindow *window, map_t *map_t, int number, sfVector2f pos);
void prt_portal(game_t *d, map_t *map_t, float elapsed, sfSprite *portal);
void coin(sfRenderWindow *window, map_t *map_t);
void my_itoa(char *buffer, int number);
float distance(sfSprite *sprite1, sfSprite *sprite2);
void mv_turo(game_t *d, map_t *map_t);
void mv_turd(game_t *d, map_t *map_t);
void mv_turt(game_t *d, map_t *map_t);
void putpls_o(game_t *d, map_t *map_t);
void mv_turq(game_t *d, map_t *map_t);
void mv_poso(game_t *d, map_t *map_t, sfFloatRect plat);
void mv_posd(game_t *d, map_t *map_t, sfFloatRect plat);
void mv_post(game_t *d, map_t *map_t, sfFloatRect plat);
void mv_posq(game_t *d, map_t *map_t, sfFloatRect plat);
void render_plat(game_t *d, map_t *map_t, int i);
void move_enemies_o(map_t *map_t, float elapsed, sfSprite *enemie, int speed, int type, int nb);
void move_enemies_o_bis(map_t *map_t, float elapsed, sfSprite *enemie, int speed, int type, int nb);
void move_enemies_o_bisbis(map_t *map_t, float elapsed, sfSprite *enemie, int speed, int type, int nb);
void prt_text_coin(sfRenderWindow *window, map_t *map_t);
void prt_price(sfRenderWindow *window, map_t *map_t, int number, sfVector2f pos);
void prt_text_life(sfRenderWindow *window, map_t *map_t);
void my_itoa(char *buffer, int number);
void set_score(float elapsed, map_t *map_t);
float distance(sfSprite *sprite1, sfSprite *sprite2);
void tur_param(game_t *d, map_t *map_t, float elapsed);
void generate_rand_enemie_o(game_t *d, map_t *map_t, float elapsed);
void generate_rand_enemie_d(game_t *d, map_t *map_t, float elapsed);
void generate_rand_enemie_t(game_t *d, map_t *map_t, float elapsed);
void prt_en(game_t *d, map_t *map_t, float elapsed);
void first_en(game_t *d, map_t *map_t, float elapsed);
void second_en(game_t *d, map_t *map_t, float elapsed);
void third_en(game_t *d, map_t *map_t, float elapsed);
tour_t *create_tower();
ftur_t *create_fturet();
stur_t *create_sturet();
ttur_t *create_tturet();
platform_t *create_platform();
qtur_t *create_qturet();
map_t *create_map();
move_t *create_movement();
enemies_t *create_enemie();
fenemie_t *create_fenemie();
senemie_t *create_senemie();
tenemie_t *create_tenemie();
void tur_shoot(game_t *d, map_t *map_t, float elapsed, sfSprite *tur);
void set_param_tur(game_t *d, map_t *map_t, float elapsed, sfSprite *tur, sfSprite *en);
double angle_sprt(sfSprite *sprite1, sfSprite *sprite2, map_t *map_t);

#endif /* !_MY_DEFENDER_H_ */
