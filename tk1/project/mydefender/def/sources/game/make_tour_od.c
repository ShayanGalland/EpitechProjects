/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** main_mydefnder.c
*/

#include "my_defender_game.h"

void bul_and(game_t *d, map_t *map_t, float elapsed, sfSprite *tur, sfSprite *bulet, int set, sfSprite *en)
{
    sfVector2f pos;

    if (distance(tur, en) < 330) {
        pos.x = sfSprite_getPosition(tur).x - sfSprite_getPosition(en).x;
        pos.y = sfSprite_getPosition(tur).y - sfSprite_getPosition(en).y;
        sfSprite_setRotation(tur, angle_sprt(tur, en, map_t));
        sfSprite_setScale(bulet, start_point(0.05f, 0.05f));
        if (map_t->tour_t->set_d[set] == 0) {
            sfSprite_setPosition(bulet, sfSprite_getPosition(tur));
            sfSound_play(map_t->sound_tir);
            map_t->tour_t->set_d[set]++;
        }
        sfSprite_move(bulet, start_point(4*(-elapsed*pos.x), 4*(-elapsed*pos.y)));
        if (distance(bulet, tur) > distance(tur, en)) {
            map_t->tour_t->set_d[set] = 0;
            pos = sfSprite_getScale(en);
        }
        if (pos.x == 0.6f && pos.y == 0.6f)
            sfSprite_setScale(en, start_point(0.5f, 0.5f));
        if (pos.x == 0.5f && pos.y == 0.5f)
            sfSprite_setScale(en, start_point(0.4f, 0.4f));
        if (pos.x == 0.4f && pos.y == 0.4f)
            sfSprite_setScale(en, start_point(0.3f, 0.3f));
        if (pos.x == 0.3f && pos.y == 0.3f)
            sfSprite_setScale(en, start_point(0.2f, 0.2f));
        if (pos.x == 0.2f && pos.y == 0.2f)
            sfSprite_setScale(en, start_point(0.1f, 0.1f));
        if (pos.x == 0.1f && pos.y == 0.1f)
            sfSprite_setPosition(en, start_point(-100000, -100000));
        sfRenderWindow_drawSprite(d->window, bulet, NULL);
    }
}

void set_param_tur_d(game_t *d, map_t *map_t, float elapsed, sfSprite *tur, sfSprite *bulet, int set)
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
    bul_and(d, map_t, elapsed, tur, bulet, set, en);
}

void bul_ano(game_t *d, map_t *map_t, float elapsed, sfSprite *tur, sfSprite *bulet, int set, sfSprite *en)
{
    sfVector2f pos;

    if (distance(tur, en) < 330) {
        pos.x = sfSprite_getPosition(tur).x - sfSprite_getPosition(en).x;
        pos.y = sfSprite_getPosition(tur).y - sfSprite_getPosition(en).y;
        sfSprite_setRotation(tur, angle_sprt(tur, en, map_t));
        sfSprite_setScale(bulet, start_point(0.05f, 0.05f));
        if (map_t->tour_t->set_o[set] == 0) {
            sfSprite_setPosition(bulet, sfSprite_getPosition(tur));
            sfSound_play(map_t->sound_tir);
            map_t->tour_t->set_o[set]++;
        }
        sfSprite_move(bulet, start_point(2*(-elapsed*pos.x), 2*(-elapsed*pos.y)));
        if (distance(bulet, tur) > distance(tur, en)) {
            map_t->tour_t->set_o[set] = 0;
            pos = sfSprite_getScale(en);
        }
        if (pos.x == 0.6f && pos.y == 0.6f)
            sfSprite_setScale(en, start_point(0.5f, 0.5f));
        if (pos.x == 0.5f && pos.y == 0.5f)
            sfSprite_setScale(en, start_point(0.4f, 0.4f));
        if (pos.x == 0.4f && pos.y == 0.4f)
            sfSprite_setScale(en, start_point(0.3f, 0.3f));
        if (pos.x == 0.3f && pos.y == 0.3f)
            sfSprite_setScale(en, start_point(0.2f, 0.2f));
        if (pos.x == 0.2f && pos.y == 0.2f)
            sfSprite_setScale(en, start_point(0.1f, 0.1f));
        if (pos.x == 0.1f && pos.y == 0.1f)
            sfSprite_setPosition(en, start_point(-100000, -100000));
        sfRenderWindow_drawSprite(d->window, bulet, NULL);
    }
}

void set_param_tur_o(game_t *d, map_t *map_t, float elapsed, sfSprite *tur, sfSprite *bulet, int set)
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
    bul_ano(d, map_t, elapsed, tur, bulet, set, en);
}

