/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** main_mydefnder.c
*/

#include "my_defender_game.h"
#include "my_struct.h"

void generate_rand_enemie_o(game_t *d, map_t *map_t, float elapsed)
{
    int number_o;

    map_t->time_en += elapsed;
    if (map_t->enemies_t->time_deploy_o <= 0 && map_t->enemies_t->nbr_en_o < MAX_EN_OO) {
        number_o = generate_random_number(0, 2000);
        if (number_o < 25) {
            if (map_t->time_en < 20)
                map_t->enemies_t->time_deploy_o = (5/map_t->time_en)*2;
            if (map_t->time_en < 60 && map_t->time_en > 20)
                map_t->enemies_t->time_deploy_o = (3/map_t->time_en)*100;
            if (map_t->time_en < 100 && map_t->time_en > 60)
                map_t->enemies_t->time_deploy_o = (1/map_t->time_en)*100;
            map_t->enemies_t->nbr_en_o++;
        }
    }
    map_t->enemies_t->time_deploy_o--;
    for (int i = 0; i < map_t->enemies_t->nbr_en_o; i++) {
        move_enemies_o(map_t, elapsed, map_t->fenemie_t[i], 200, 0, i);
        map_t->enemies_t->fen_deploy[i] = 1;
    }
}

void generate_rand_enemie_d(game_t *d, map_t *map_t, float elapsed)
{
    int number_d;

    if(map_t->enemies_t->time_deploy_d <= 0 && map_t->enemies_t->nbr_en_d < MAX_EN_OD) {
        number_d = generate_random_number(0, 2000);
        if(number_d < 25) {
            if(map_t->time_en < 60 && map_t->time_en > 40)
                map_t->enemies_t->time_deploy_d = (3/map_t->time_en)*100;
            if (map_t->time_en < 100 && map_t->time_en > 60)
                map_t->enemies_t->time_deploy_d = (1/map_t->time_en)*100;
            map_t->enemies_t->nbr_en_d++;
        }
    }
    if (map_t->time_en > 40)
        map_t->enemies_t->time_deploy_d--;
    for (int i = 0; i < map_t->enemies_t->nbr_en_d; i++) {
        move_enemies_o(map_t, elapsed, map_t->senemie_t[i], 300, 1, i);
        map_t->enemies_t->sen_deploy[i] = 1;
    }
}
void generate_rand_enemie_t(game_t *d, map_t *map_t, float elapsed)
{
    int number_t;

    if (map_t->enemies_t->time_deploy_t <= 0 && map_t->enemies_t->nbr_en_t < MAX_EN_OT) {
        number_t = generate_random_number(0, 2000);
        if (number_t < 25) {
            if (map_t->time_en < 100 && map_t->time_en > 60)
                map_t->enemies_t->time_deploy_t = (1/map_t->time_en)*100;
            map_t->enemies_t->nbr_en_t++;
        }
    }
    if (map_t->time_en > 60)
        map_t->enemies_t->time_deploy_t--;
    for (int i = 0; i < map_t->enemies_t->nbr_en_t; i++) {
        move_enemies_o(map_t, elapsed, map_t->tenemie_t[i], 400, 2, i);
        map_t->enemies_t->ten_deploy[i] = 1;
    }
}

void map_one(game_t *d, map_t *map_t, float elapsed)
{
    prt_mp(d, map_t);
    first_en(d, map_t, elapsed);
    second_en(d, map_t, elapsed);
    third_en(d, map_t, elapsed);
    generate_rand_enemie_o(d, map_t, elapsed);
    generate_rand_enemie_d(d, map_t, elapsed);
    generate_rand_enemie_t(d, map_t, elapsed);
    prt_en(d, map_t, elapsed);
    prt_portal(d, map_t, elapsed, map_t->move_t->rp);
    prt_portal(d, map_t, elapsed, map_t->move_t->gp);
}