/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** main_mydefnder.c
*/

#include "my_defender_game.h"

float cardrant(sfVector2f P_sprite1, sfVector2f P_sprite2, double add, map_t *map_t)
{
    float angle = 0;

    map_t->ab = (float)sqrt((map_t->ac * map_t->ac) + (map_t->cb * map_t->cb));
    angle = (float)asinf(map_t->cb/map_t->ab) + add;
    return angle;
}

void sum_cadr(int abscb, int absac, map_t *map_t)
{
    map_t->cb = abs(abscb);
    map_t->ac = abs(absac);
}

float angle_sprt(sfSprite *sprite1, sfSprite *sprite2, map_t *map_t)
{
    sfVector2f P_sprite1 = sfSprite_getPosition(sprite1);
    sfVector2f P_sprite2 = sfSprite_getPosition(sprite2);

    if (P_sprite2.y > P_sprite1.y && P_sprite2.x > P_sprite1.x) {
        sum_cadr(P_sprite1.y - P_sprite2.y, P_sprite1.x - P_sprite2.x, map_t);
        map_t->angle = cardrant(P_sprite1, P_sprite2, 0, map_t);
    }
    if (P_sprite2.y > P_sprite1.y && P_sprite2.x < P_sprite1.x) {
        sum_cadr(P_sprite1.x - P_sprite2.x, P_sprite1.y - P_sprite2.y, map_t);
        map_t->angle = cardrant(P_sprite1, P_sprite2, T_PI/2, map_t);
    }
    if (P_sprite2.y < P_sprite1.y && P_sprite2.x < P_sprite1.x) {
        sum_cadr(P_sprite1.y - P_sprite2.y, P_sprite1.x - P_sprite2.x, map_t);
        map_t->angle = cardrant(P_sprite1, P_sprite2, T_PI, map_t);
    }
    if (P_sprite2.y < P_sprite1.y && P_sprite2.x > P_sprite1.x) {
        sum_cadr(P_sprite1.x - P_sprite2.x, P_sprite1.y - P_sprite2.y, map_t);
        map_t->angle = cardrant(P_sprite1, P_sprite2, (T_PI + T_PI/2), map_t);
    }
    return map_t->angle*180/T_PI;
}
/*
float angle_sprt(sfSprite *sprite1, sfSprite *sprite2, map_t *map_t)
{
    float angle = 0;
    float ac = 0;
    float cb = 0;
    float ab = 0;
    sfVector2f P_sprite1 = sfSprite_getPosition(sprite1);
    sfVector2f P_sprite2 = sfSprite_getPosition(sprite2);

    if (P_sprite2.y > P_sprite1.y && P_sprite2.x > P_sprite1.x) {
        cb = abs(P_sprite1.y - P_sprite2.y);
        ac = abs(P_sprite1.x - P_sprite2.x);
        ab = (float)sqrt((ac * ac) + (cb * cb));
        angle = (float)asinf(cb/ab);
    }
    else if(P_sprite2.y > P_sprite1.y && P_sprite2.x < P_sprite1.x) {
        cb = abs(P_sprite1.x - P_sprite2.x);
        ac = abs(P_sprite1.y - P_sprite2.y);
        ab = (float)sqrt((ac * ac) + (cb * cb));
        angle = (float)asinf(cb/ab) + T_PI/2;
    }
    else if(P_sprite2.y < P_sprite1.y && P_sprite2.x < P_sprite1.x) {
        cb = abs(P_sprite1.y - P_sprite2.y);
        ac = abs(P_sprite1.x - P_sprite2.x);
        ab = (float)sqrt((ac * ac) + (cb * cb));
        angle = (float)asinf(cb/ab) + T_PI;
    }
    else if(P_sprite2.y < P_sprite1.y && P_sprite2.x > P_sprite1.x) {
        cb = abs(P_sprite1.x - P_sprite2.x);
        ac = abs(P_sprite1.y - P_sprite2.y);
        ab = (float)sqrt((ac * ac) + (cb * cb));
        angle = (float)asinf(cb/ab) + T_PI + T_PI/2;
    }
    angle = angle * 180/T_PI;
    return angle;
}
*/
float distance(sfSprite *sprite1, sfSprite *sprite2)
{
    float distance = 0;
    float deferent_y = 0;
    float deferent_x = 0;
    sfVector2f P_sprite1 = sfSprite_getPosition(sprite1);
    sfVector2f P_sprite2 = sfSprite_getPosition(sprite2);

    deferent_x = P_sprite1.x - P_sprite2.x;
    deferent_y = P_sprite1.y - P_sprite2.y;
    distance = deferent_x * deferent_x + deferent_y * deferent_y;
    distance = sqrt(distance);
    return (distance);
}

void tur_param(game_t *d, map_t *map_t, float elapsed)
{
    for (int i = 1; i != MAX_PLAT_O; i++) {
        if (map_t->tour_t->fturet_posed[i] != 0)
            set_param_tur_o(d, map_t, elapsed, map_t->ftur_t[i], map_t->fbulet_t[i], i);
        if (map_t->tour_t->sturet_posed[i] != 0)
            set_param_tur_d(d, map_t, elapsed, map_t->stur_t[i], map_t->sbulet_t[i], i);
        if (map_t->tour_t->tturet_posed[i] != 0)
            set_param_tur_t(d, map_t, elapsed, map_t->ttur_t[i], map_t->tbulet_t[i], i);
        if (map_t->tour_t->qturet_posed[i] != 0)
            set_param_tur_q(d, map_t, elapsed, map_t->qtur_t[i], map_t->qbulet_t[i], i);
    }
}