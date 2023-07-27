/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** main_mydefnder.c
*/

#include "my_defender_game.h"
#include "my.h"
#include "my_struct.h"

void render_plat(game_t *d, map_t *map_t, int i)
{
    sfRenderWindow_drawSprite(d->window, map_t->platform_t[i], NULL);
}