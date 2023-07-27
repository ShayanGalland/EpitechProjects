/*
** EPITECH PROJECT, 2022
** my_defender.C
** File description:
** free_all
*/

#include "my_defender_game.h"

void mv_turo(game_t *d, map_t *map_t)
{
    sfFloatRect plat;

    if (d->event.type == sfEvtMouseButtonPressed && map_t->coin_count > 60) {
        map_t->mouse.x = sfMouse_getPosition(d->window).x;
        map_t->mouse.y = sfMouse_getPosition(d->window).y;
        sfFloatRect box_o = sfSprite_getGlobalBounds(map_t->ftur_t[0]);
        if (sfFloatRect_contains(&box_o, map_t->mouse.x, map_t->mouse.y))
            map_t->tour_t->validate_o = 1;
    }
    if (map_t->tour_t->validate_o == 1) {
        map_t->mouse.x = sfMouse_getPosition(d->window).x;
        map_t->mouse.y = sfMouse_getPosition(d->window).y;
        sfSprite_setPosition(map_t->ftur_t[0], map_t->mouse);
    }
    mv_poso(d, map_t, plat);
}

void mv_turd(game_t *d, map_t *map_t)
{
    sfFloatRect plat;

    if (d->event.type == sfEvtMouseButtonPressed && map_t->coin_count > 80) {
        map_t->mouse.x = sfMouse_getPosition(d->window).x;
        map_t->mouse.y = sfMouse_getPosition(d->window).y;
        sfFloatRect box_d = sfSprite_getGlobalBounds(map_t->stur_t[0]);
        if (sfFloatRect_contains(&box_d, map_t->mouse.x, map_t->mouse.y))
            map_t->tour_t->validate_d = 1;
    }
    if (map_t->tour_t->validate_d == 1) {
        map_t->mouse.x = sfMouse_getPosition(d->window).x;
        map_t->mouse.y = sfMouse_getPosition(d->window).y;
        sfSprite_setPosition(map_t->stur_t[0], map_t->mouse);
    }
    mv_posd(d, map_t, plat);
}

void mv_turt(game_t *d, map_t *map_t)
{
    sfFloatRect plat;

    if (d->event.type == sfEvtMouseButtonPressed && map_t->coin_count > 100) {
        map_t->mouse.x = sfMouse_getPosition(d->window).x;
        map_t->mouse.y = sfMouse_getPosition(d->window).y;
        sfFloatRect box_t = sfSprite_getGlobalBounds(map_t->ttur_t[0]);
        if (sfFloatRect_contains(&box_t, map_t->mouse.x, map_t->mouse.y))
            map_t->tour_t->validate_t = 1;
    }
    if (map_t->tour_t->validate_t == 1) {
        map_t->mouse.x = sfMouse_getPosition(d->window).x;
        map_t->mouse.y = sfMouse_getPosition(d->window).y;
        sfSprite_setPosition(map_t->ttur_t[0], map_t->mouse);
    }
    mv_post(d, map_t, plat);
}

void mv_turq(game_t *d, map_t *map_t)
{
    sfFloatRect plat;

    if (d->event.type == sfEvtMouseButtonPressed && map_t->coin_count > 200) {
        map_t->mouse.x = sfMouse_getPosition(d->window).x;
        map_t->mouse.y = sfMouse_getPosition(d->window).y;
        sfFloatRect box_t = sfSprite_getGlobalBounds(map_t->qtur_t[0]);
        if (sfFloatRect_contains(&box_t, map_t->mouse.x, map_t->mouse.y))
            map_t->tour_t->validate_q = 1;
    }
    if (map_t->tour_t->validate_q == 1) {
        map_t->mouse.x = sfMouse_getPosition(d->window).x;
        map_t->mouse.y = sfMouse_getPosition(d->window).y;
        sfSprite_setPosition(map_t->qtur_t[0], map_t->mouse);
    }
    mv_posq(d, map_t, plat);
}

void mv_turs(game_t *d, map_t *map_t)
{
    mv_turo(d, map_t);
    mv_turd(d, map_t);
    mv_turt(d, map_t);
    mv_turq(d, map_t);
}