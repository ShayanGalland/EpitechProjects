/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** project in c
*/
#include "function.h"

void create_and_anim(float elapse, game_t *game_t)
{
    game_t->time_animation += elapse;
    if (game_t->time_animation > game_t->frame) {
        game_t->i += 1;
        if (game_t->i == 5)
            game_t->i = 1;
        game_t->frame += 0.10f;
    }
    sfIntRect rect;
    rect.left = 280*game_t->i;
    rect.top = 0;
    rect.height = 385;
    rect.width = 280;
    sfSprite_setTextureRect(game_t->hero_spr, rect);
}
