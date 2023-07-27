/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** main_mydefnder.c
*/

#include "my_defender_game.h"

void move_enemies_o_bisbis(map_t *map_t, float elapsed, sfSprite *enemie, int speed, int type, int nb)
{
    if (sfSprite_getPosition(enemie).y < 605 && map_t->move_t->mv[6][type][nb] == 1) {
        map_t->move_t->mv[6][type][nb] = 0;
        map_t->move_t->mv[7][type][nb] = 1;
    }
    if (map_t->move_t->mv[7][type][nb]  == 1)
        sfSprite_move(enemie, start_point(speed*elapsed, 0));
    if (sfSprite_getPosition(enemie).x > 1820 && map_t->move_t->mv[7][type][nb] == 1) {
       map_t->move_t->mv[7][type][nb] = 0;
       map_t->move_t->mv[8][type][nb] = 1;
    }
    if (map_t->move_t->mv[8][type][nb] == 1)
        sfSprite_move(enemie, start_point(0, speed*elapsed));
    if (sfSprite_getPosition(enemie).y > 1200 && map_t->move_t->mv[8][type][nb] == 1) {
        map_t->move_t->mv[8][type][nb]  = 0;
        map_t->move_t->mv[9][type][nb]  = 1;
        if (map_t->move_t->mv[9][type][nb]  == 1) {
            map_t->life_count--;
            sfSprite_move(enemie, start_point(0, 0));
        }
    }
}

void move_enemies_o_bis(map_t *map_t, float elapsed, sfSprite *enemie, int speed, int type, int nb)
{
    if (sfSprite_getPosition(enemie).y > 930 && map_t->move_t->mv[3][type][nb] == 1) {
        map_t->move_t->mv[3][type][nb] = 0;
        map_t->move_t->mv[4][type][nb] = 1;
    }
    if (map_t->move_t->mv[4][type][nb]  == 1)
        sfSprite_move(enemie, start_point(0, speed*elapsed));
    if (sfSprite_getPosition(enemie).x < 970 && map_t->move_t->mv[4][type][nb] == 1) {
        map_t->move_t->mv[4][type][nb] = 0;
        map_t->move_t->mv[5][type][nb] = 1;
    }
    if (map_t->move_t->mv[5][type][nb]  == 1)
        sfSprite_move(enemie, start_point(speed*elapsed, 0));
    if (sfSprite_getPosition(enemie).x > 1250 && map_t->move_t->mv[5][type][nb] == 1) {
        map_t->move_t->mv[5][type][nb] = 0;
        map_t->move_t->mv[6][type][nb] = 1;
    }
    if (map_t->move_t->mv[6][type][nb]  == 1)
        sfSprite_move(enemie, start_point(0, -speed*elapsed));
    move_enemies_o_bisbis(map_t, elapsed, enemie, speed, type, nb);
}


void move_enemies_o(map_t *map_t, float elapsed, sfSprite *enemie, int speed, int type, int nb)
{
    if (map_t->move_t->mv[0][type][nb] == 0)
        sfSprite_move(enemie, start_point(-speed*elapsed, 0));
    if (sfSprite_getPosition(enemie).x < 1260 && map_t->move_t->mv[0][type][nb] == 0) {
        map_t->move_t->mv[0][type][nb]  = 1;
        map_t->move_t->mv[1][type][nb]  = 1;
    }
    if (map_t->move_t->mv[1][type][nb] == 1)
        sfSprite_move(enemie, start_point(0, speed*elapsed));
    if (sfSprite_getPosition(enemie).y > 400 && map_t->move_t->mv[1][type][nb] == 1) {
        map_t->move_t->mv[1][type][nb] = 0;
        map_t->move_t->mv[2][type][nb] = 1;
    }
    if (map_t->move_t->mv[2][type][nb]  == 1)
        sfSprite_move(enemie, start_point(-speed*elapsed, 0));
    if (sfSprite_getPosition(enemie).x < 500 && map_t->move_t->mv[2][type][nb] == 1) {
        map_t->move_t->mv[2][type][nb] = 0;
        map_t->move_t->mv[3][type][nb] = 1;
    }
    if (map_t->move_t->mv[3][type][nb]  == 1)
        sfSprite_move(enemie, start_point(0, speed*elapsed));
    move_enemies_o_bis(map_t, elapsed, enemie, speed, type, nb);
}