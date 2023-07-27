/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** main_mydefnder.c
*/

#include "my_defender_game.h"

void bul_anq_bis(game_t *d, sfSprite *en, sfVector2f pos, sfSprite *bulet)
{
    if (pos.x == 0.6f && pos.y == 0.6f)
        sfSprite_setScale(en, start_point(0.55f, 0.55f));
    if (pos.x == 0.55f && pos.y == 0.55f)
        sfSprite_setScale(en, start_point(0.5f, 0.5f));
    if (pos.x == 0.5f && pos.y == 0.5f)
        sfSprite_setScale(en, start_point(0.45f, 0.45f));
    if (pos.x == 0.45f && pos.y == 0.45f)
        sfSprite_setScale(en, start_point(0.4f, 0.4f));
    if (pos.x == 0.4f && pos.y == 0.4f)
        sfSprite_setScale(en, start_point(0.35f, 0.35f));
    if (pos.x == 0.35f && pos.y == 0.35f)
        sfSprite_setScale(en, start_point(0.3f, 0.3f));
    if (pos.x == 0.3f && pos.y == 0.3f)
        sfSprite_setScale(en, start_point(0.25f, 0.25f));
    if (pos.x == 0.25f && pos.y == 0.25f)
        sfSprite_setScale(en, start_point(0.2f, 0.2f));
    if (pos.x == 0.2f && pos.y == 0.2f)
        sfSprite_setScale(en, start_point(0.15f, 0.15f));
    if (pos.x == 0.15f && pos.y == 0.15f)
        sfSprite_setScale(en, start_point(0.1f, 0.1f));
    if (pos.x == 0.1f && pos.y == 0.1f)
        sfSprite_setScale(en, start_point(0.05f, 0.05f));
    if (pos.x == 0.05f && pos.y == 0.05f)
        sfSprite_setPosition(en, start_point(-100000, -100000));
    sfRenderWindow_drawSprite(d->window, bulet, NULL);
}

void bul_anq(game_t *d, map_t *map_t, float elapsed, sfSprite *tur, sfSprite *bulet, int set, sfSprite *en)
{
    sfVector2f pos;

    if (distance(tur, en) < 200) {
        pos.x = sfSprite_getPosition(tur).x - sfSprite_getPosition(en).x;
        pos.y = sfSprite_getPosition(tur).y - sfSprite_getPosition(en).y;
        sfSprite_setRotation(tur, angle_sprt(tur, en, map_t));
        sfSprite_setScale(bulet, start_point(0.05f, 0.05f));
        if (map_t->tour_t->set_q[set] == 0) {
            sfSprite_setPosition(bulet, sfSprite_getPosition(tur));
            sfSound_play(map_t->sound_tir);
            map_t->tour_t->set_q[set]++;
        }
        sfSprite_move(bulet, start_point(10*(-elapsed*pos.x), 10*(-elapsed*pos.y)));
        if (distance(bulet, tur) > distance(tur, en)) {
            map_t->tour_t->set_q[set] = 0;
            pos = sfSprite_getScale(en);
        }
        bul_anq_bis(d, en, pos, bulet);
    }
}

void set_param_tur_q(game_t *d, map_t *map_t, float elapsed, sfSprite *tur, sfSprite *bulet, int set)
{
    sfSprite *en;
    float dist = 1010;
    float res;
    float ret;

    for (int i = 0; i != MAX_EN_OO; i++) {
        if (map_t->enemies_t->fen_deploy[i] != 0) {
            res = distance(tur, map_t->fenemie_t[i]);
            if (res < dist) {
                dist = res;
                en = map_t->fenemie_t[i];
            }
        }
    }
    for (int j = 0; j != MAX_EN_OD; j++) {
        if (map_t->enemies_t->sen_deploy[j] != 0) {
            res = distance(tur, map_t->senemie_t[j]);
            if (res < dist) {
                dist = res;
                en = map_t->senemie_t[j];
            }
        }
    }
    for (int k = 0; k != MAX_EN_OT; k++) {
        if (map_t->enemies_t->ten_deploy[k] != 0) {
            res = distance(tur, map_t->tenemie_t[k]);
            if (res < dist) {
                dist = res;
                en = map_t->tenemie_t[k];
            }
        }
    }
    bul_anq(d, map_t, elapsed, tur, bulet, set, en);
}

void bul_ant(game_t *d, map_t *map_t, float elapsed, sfSprite *tur, sfSprite *bulet, int set, sfSprite *en)
{
    sfVector2f pos;

    if (distance(tur, en) < 330) {
        pos.x = sfSprite_getPosition(tur).x - sfSprite_getPosition(en).x;
        pos.y = sfSprite_getPosition(tur).y - sfSprite_getPosition(en).y;
        sfSprite_setRotation(tur, angle_sprt(tur, en, map_t));
        sfSprite_setScale(bulet, start_point(0.14f, 0.14f));
        if (map_t->tour_t->set_t[set] == 0) {
            sfSprite_setPosition(bulet, sfSprite_getPosition(tur));
            sfSound_play(map_t->sound_bolet);
            map_t->tour_t->set_t[set]++;
        }
        sfSprite_move(bulet, start_point(0.7*(-elapsed*pos.x), 0.7*(-elapsed*pos.y)));
        if (distance(bulet, tur) > distance(tur, en)) {
            map_t->tour_t->set_t[set] = 0;
            pos = sfSprite_getScale(en);
        }
        if (pos.x == 0.6f && pos.y == 0.6f)
            sfSprite_setPosition(en, start_point(-100000, -100000));
        if (pos.x == 0.5f && pos.y == 0.5f)
            sfSprite_setPosition(en, start_point(-100000, -100000));
        if (pos.x == 0.4f && pos.y == 0.4f)
            sfSprite_setPosition(en, start_point(-100000, -100000));
        sfRenderWindow_drawSprite(d->window, bulet, NULL);
    }
}

void set_param_tur_t(game_t *d, map_t *map_t, float elapsed, sfSprite *tur, sfSprite *bulet, int set)
{
    sfSprite *en;
    float dist = 1010;
    float res;
    float ret;

    for (int i = 0; i != MAX_EN_OO; i++) {
        if (map_t->enemies_t->fen_deploy[i] != 0) {
            res = distance(tur, map_t->fenemie_t[i]);
            if (res < dist) {
                dist = res;
                en = map_t->fenemie_t[i];
            }
        }
    }
    for (int j = 0; j != MAX_EN_OD; j++) {
        if (map_t->enemies_t->sen_deploy[j] != 0) {
            res = distance(tur, map_t->senemie_t[j]);
            if (res < dist) {
                dist = res;
                en = map_t->senemie_t[j];
            }
        }
    }
    for (int k = 0; k != MAX_EN_OT; k++) {
        if (map_t->enemies_t->ten_deploy[k] != 0) {
            res = distance(tur, map_t->tenemie_t[k]);
            if (res < dist) {
                dist = res;
                en = map_t->tenemie_t[k];
            }
        }
    }
    bul_ant(d, map_t, elapsed, tur, bulet, set, en);
}