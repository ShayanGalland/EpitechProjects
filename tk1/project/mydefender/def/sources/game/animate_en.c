/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** main_mydefnder.c
*/

#include "my_defender_game.h"
#include "my_struct.h"

void first_en(game_t *d, map_t *map_t, float elapsed)
{
    sfIntRect rect;

    d->time_animation_o += elapsed;
    if (d->time_animation_o > map_t->enemies_t->frame_o) {
        map_t->enemies_t->next_frame_o += 1;
        if (map_t->enemies_t->next_frame_o == 6)
            map_t->enemies_t->next_frame_o = 1;
        map_t->enemies_t->frame_o += 0.10f;
    }
    rect.left = 202*map_t->enemies_t->next_frame_o;
    rect.top = 0;
    rect.height = 180;
    rect.width = 190;
    for (int i = 0;i != MAX_EN_OO;i++) {
        sfSprite_setTextureRect(map_t->fenemie_t[i], rect);
    }
}

void second_en(game_t *d, map_t *map_t, float elapsed)
{
    sfIntRect rect;

    d->time_animation_d += elapsed;
    if (d->time_animation_d > map_t->enemies_t->frame_d) {
        map_t->enemies_t->next_frame_d += 1;
        if (map_t->enemies_t->next_frame_d == 5)
            map_t->enemies_t->next_frame_d = 1;
        map_t->enemies_t->frame_d += 0.10f;
    }
    rect.left = (1361/5)*map_t->enemies_t->next_frame_d;
    rect.top = 0;
    rect.height = 153;
    rect.width = 250;
    for (int i = 0;i != MAX_EN_OD;i++) {
        sfSprite_setTextureRect(map_t->senemie_t[i], rect);
    }
}

void third_en(game_t *d, map_t *map_t, float elapsed)
{
    sfIntRect rect;

    d->time_animation_t += elapsed;
    if (d->time_animation_t > map_t->enemies_t->frame_t) {
        map_t->enemies_t->next_frame_t += 1;
        if (map_t->enemies_t->next_frame_t == 4)
            map_t->enemies_t->next_frame_t = 1;
        map_t->enemies_t->frame_t += 0.10f;
    }
    rect.left = (1024/4)*map_t->enemies_t->next_frame_t;
    rect.top = 0;
    rect.height = 175;
    rect.width = 256;
    for (int i = 0;i != MAX_EN_OT;i++) {
        sfSprite_setTextureRect(map_t->tenemie_t[i], rect);

    }
}