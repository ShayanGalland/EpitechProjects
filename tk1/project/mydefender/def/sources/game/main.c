/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** main_mydefnder.c
*/

#include "my_defender_game.h"
#include "my.h"

sfVector2f start_point(float a, float b)
{
    sfVector2f point;
    point.y = b;
    point.x = a;
    return point;
}

void usage(void)
{
    my_putstr("########################################\n");
    my_putstr("USAGE:\n");
    my_putstr("     ./my_defender ->to start game\n");
    my_putstr("     - presse Escap to exit game\n");
    my_putstr("########################################\n");
}

void analyse_events(game_t *d, map_t *map_t)
{
    if (d->event.type == sfEvtClosed)
        sfRenderWindow_close(d->window);
}