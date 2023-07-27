
/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "function.h"

void set_pos(back_t *back_t)
{
    sfSprite_setPosition(back_t->sprite_un, start_point(0, 0));
    sfSprite_setPosition(back_t->sprite_deux, start_point(800, 0));
    sfSprite_setPosition(back_t->sprite_trois, start_point(1600, 0));
    sfSprite_setPosition(back_t->sprite_quatre, start_point(0, 75));
    sfSprite_setPosition(back_t->sprite_cinq, start_point(3500, 75));
    sfSprite_setPosition(back_t->sprite_sept, start_point(0, 500));
    sfSprite_setPosition(back_t->sprite_huit, start_point(470, 500));
    sfSprite_setPosition(back_t->sprite_neuf, start_point(940, 500));
}