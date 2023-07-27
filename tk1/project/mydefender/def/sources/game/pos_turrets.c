/*
** EPITECH PROJECT, 2022
** my_defender.C
** File description:
** free_all
*/

#include "my_defender_game.h"

void mv_poso(game_t *d, map_t *map_t, sfFloatRect plat)
{
    for (int i = 0; i < MAX_PLAT_O; i++) {
        plat = sfSprite_getGlobalBounds(map_t->platform_t[i]);
        map_t->mouse.x = sfMouse_getPosition(d->window).x;
        map_t->mouse.y = sfMouse_getPosition(d->window).y;
        if (d->event.type == sfEvtMouseButtonReleased &&
        sfFloatRect_contains(&plat, map_t->mouse.x, map_t->mouse.y) && map_t->tour_t->validate_o == 1
        && map_t->coin_count >= 60) {
            sfVector2f pos;
            pos.x = sfSprite_getPosition(map_t->platform_t[i]).x+60;
            pos.y = sfSprite_getPosition(map_t->platform_t[i]).y+60;
            sfSprite_setPosition(map_t->ftur_t[i+1], pos);
            map_t->tour_t->validate_o = 0;
            map_t->coin_count -= 60;
            map_t->tour_t->fturet_posed[i+1] = 1;
            map_t->tour_t->set_o[i] = 0;
        }
        else if (d->event.type == sfEvtMouseButtonReleased) {
            if (i == MAX_PLAT_O)
                map_t->tour_t->validate_o = 0;
            sfSprite_setPosition(map_t->ftur_t[0], start_point(200, 110));
        }
    }
}

void mv_posd(game_t *d, map_t *map_t, sfFloatRect plat)
{
    for (int i = 0; i < MAX_PLAT_O; i++) {
        plat = sfSprite_getGlobalBounds(map_t->platform_t[i]);
        map_t->mouse.x = sfMouse_getPosition(d->window).x;
        map_t->mouse.y = sfMouse_getPosition(d->window).y;
        if (d->event.type == sfEvtMouseButtonReleased &&
        sfFloatRect_contains(&plat, map_t->mouse.x, map_t->mouse.y) && map_t->tour_t->validate_d == 1
        && map_t->coin_count >= 80) {
            sfVector2f pos;
            pos.x = sfSprite_getPosition(map_t->platform_t[i]).x+60;
            pos.y = sfSprite_getPosition(map_t->platform_t[i]).y+60;
            sfSprite_setPosition(map_t->stur_t[i+1], pos);
            map_t->tour_t->validate_d = 0;
            map_t->coin_count -= 80;
            map_t->tour_t->sturet_posed[i+1] = 1;
            map_t->tour_t->set_d[i] = 0;
        }
        else if (d->event.type == sfEvtMouseButtonReleased) {
            if (i == MAX_PLAT_O)
                map_t->tour_t->validate_d = 0;
            sfSprite_setPosition(map_t->stur_t[0], start_point(200, 340));
        }
    }
}

void mv_post(game_t *d, map_t *map_t, sfFloatRect plat)
{
    for (int i = 0; i < MAX_PLAT_O; i++) {
        plat = sfSprite_getGlobalBounds(map_t->platform_t[i]);
        map_t->mouse.x = sfMouse_getPosition(d->window).x;
        map_t->mouse.y = sfMouse_getPosition(d->window).y;
        if (d->event.type == sfEvtMouseButtonReleased && sfFloatRect_contains(&plat, map_t->mouse.x, map_t->mouse.y) && map_t->tour_t->validate_t == 1 && map_t->coin_count >= 100) {
            sfVector2f pos;
            pos.x = sfSprite_getPosition(map_t->platform_t[i]).x+60;
            pos.y = sfSprite_getPosition(map_t->platform_t[i]).y+60;
            sfSprite_setPosition(map_t->ttur_t[i+1], pos);
            map_t->tour_t->validate_t = 0;
            map_t->coin_count -= 100;
            map_t->tour_t->tturet_posed[i+1] = 1;
            map_t->tour_t->set_t[i] = 0;
        }
        else if (d->event.type == sfEvtMouseButtonReleased) {
            if (i == MAX_PLAT_O)
                map_t->tour_t->validate_t = 0;
        sfSprite_setPosition(map_t->ttur_t[0], start_point(200, 570));
        }
    }
}

void mv_posq(game_t *d, map_t *map_t, sfFloatRect plat)
{

    for (int i = 0; i < MAX_PLAT_O; i++) {
        plat = sfSprite_getGlobalBounds(map_t->platform_t[i]);
        map_t->mouse.x = sfMouse_getPosition(d->window).x;
        map_t->mouse.y = sfMouse_getPosition(d->window).y;
        if (d->event.type == sfEvtMouseButtonReleased && sfFloatRect_contains(&plat, map_t->mouse.x, map_t->mouse.y) && map_t->tour_t->validate_q == 1 && map_t->coin_count >= 200) {
            sfVector2f pos;
            pos.x = sfSprite_getPosition(map_t->platform_t[i]).x+60;
            pos.y = sfSprite_getPosition(map_t->platform_t[i]).y+60;
            sfSprite_setPosition(map_t->qtur_t[i+1], pos);
            map_t->tour_t->validate_q = 0;
            map_t->coin_count -= 200;
            map_t->tour_t->qturet_posed[i+1] = 1;
            map_t->tour_t->set_q[i] = 0;
            }
            else if (d->event.type == sfEvtMouseButtonReleased) {
                if (i == MAX_PLAT_O)
                    map_t->tour_t->validate_q = 0;
                sfSprite_setPosition(map_t->qtur_t[0], start_point(225, 800));
        }
    }
}