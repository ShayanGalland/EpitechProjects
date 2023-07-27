/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** project in c
*/
#ifndef _FUNCTION_H
#define _FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include "SFML/Graphics.h"
#include "SFML/System.h"
#include "SFML/Audio.h"
struct ennemy{
    sfTexture *texture;
    sfSprite *sprite;
    int is_active;
};
typedef struct ennemy ennemy_t;
struct game {
    sfClock *game_clock;
    sfVector2f all_par;
    sfVector2f pos_her;
    sfVector2f her_scl;
    sfVector2f hero_vlc;
    sfTexture *tex_hero;
    sfTexture *enemies_tex;
    ennemy_t enemies[5];
    sfSprite *hero_spr;
    char *rd_mp;
    float time_e;
    float fram_e;
    float time_animation;
    float frame;
    int score;
    int l;
    int m;
    int next_frame;
    int i;
    int n;
    sfSound* jump_sound;
    sfSound* music_sound;
    sfFont* font;
    sfText *score_text;
};
typedef struct game game_t;
struct back {
    sfTexture *tex_un;
    sfTexture *tex_deux;
    sfTexture *tex_trois;
    sfTexture *tex_quatre;
    sfTexture *tex_cinq;
    sfTexture *tex_six;
    sfTexture *tex_sept;
    sfTexture *tex_huit;
    sfTexture *tex_neuf;
    sfSprite *sprite_un;
    sfSprite *sprite_deux;
    sfSprite *sprite_trois;
    sfSprite *sprite_quatre;
    sfSprite *sprite_cinq;
    sfSprite *sprite_six;
    sfSprite *sprite_sept;
    sfSprite *sprite_huit;
    sfSprite *sprite_neuf;
};
typedef struct back back_t;
sfRenderWindow *create_render_window(int X, int Y, int resolution);
sfVector2f start_point(float a, float b);
sfSprite *create_sprite(sfTexture *texture);
game_t *game_stat();
back_t *back_stat();
void help(char **argv, int argc);
void set_pos(back_t *back_t);
int my_strcmp(const char* str1, const char* str2);
void move_spr(float elapsed, back_t *back_t, game_t *game_t);
int my_strlen(char const *str);
void hero (float elapse, sfRenderWindow *renderWindow, game_t *game_t);
void create_and_anim(float elapse, game_t *game_t);
void event_close(sfRenderWindow *renderWindow);
void parallax(sfRenderWindow *renderWindow, float elapsed, back_t *back_t, game_t *game_t);
int main(int argc, char **argv);
int enemies(char **argv, game_t *game_t);
void draw_en(float elapsed, sfRenderWindow *window, game_t *game_t);
void wait_for_keypressed(sfRenderWindow *window);
#endif
