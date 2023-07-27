/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** main_mydefnder.c
*/

#include "my_defender_game.h"
#include "my.h"

move_t *create_movement()
{
    move_t *make_movement = malloc(sizeof(move_t));

    make_movement->mv = malloc(sizeof(int**)*11);
    for (int j = 0; j < 11; j++)
            make_movement->mv[j] = malloc(sizeof(int*)*3);
    for (int j = 0; j < 11; j++) {
             make_movement->mv[j][0] = malloc(sizeof(int)*MAX_EN_OO);
             make_movement->mv[j][1] = malloc(sizeof(int)*MAX_EN_OD);
             make_movement->mv[j][2] = malloc(sizeof(int)*MAX_EN_OT);
    }
    for (int i = 0; i < 11; i++) {
        for (int k = 0; k != MAX_EN_OO; k++)
            make_movement->mv[i][0][k] = 0;
        for (int k = 0; k != MAX_EN_OD; k++)
            make_movement->mv[i][1][k] = 0;
        for (int k = 0; k != MAX_EN_OT; k++)
            make_movement->mv[i][2][k] = 0;
    }
    make_movement->tgp = sfTexture_createFromFile("asset/green_por.png", NULL);
    make_movement->gp = create_sprite(make_movement->tgp);
    make_movement->trp = sfTexture_createFromFile("asset/red_por.png", NULL);
    make_movement->rp = create_sprite(make_movement->trp);
    make_movement->frame_r = 2.0f;
    make_movement->next_frame_r = 1;
    return make_movement;
}

map_t *create_map()
{
    map_t *make_map = malloc(sizeof(map_t));

    make_map->tlife = sfTexture_createFromFile("asset/txt/hrt.png", NULL);
    make_map->life = create_sprite(make_map->tlife);
    make_map->life_count = 30;
    make_map->tcoin = sfTexture_createFromFile("asset/txt/coin.png", NULL);
    make_map->coin = create_sprite(make_map->tcoin);
    make_map->coin_count = 100;
    make_map->tmp_o = sfTexture_createFromFile("asset/map/map1.png", NULL);
    make_map->mp_o = create_sprite(make_map->tmp_o);
    make_map->tmp_d = sfTexture_createFromFile("asset/map/map2.png", NULL);
    make_map->mp_d = create_sprite(make_map->tmp_d);
    make_map->tmp_t = sfTexture_createFromFile("asset/map/map3.png", NULL);
    make_map->mp_t = create_sprite(make_map->tmp_t);
    make_map->tmp_bo = sfTexture_createFromFile("asset/board.png", NULL);
    make_map->mp_bo = create_sprite(make_map->tmp_bo);
    make_map->tour_t = create_tower();
    make_map->enemies_t = create_enemie();
    make_map->move_t = create_movement();
    make_map->in = 0;
    make_map->time_en = 0;
    for (int i = 0; i != MAX_PLAT_O; i++)
        make_map->ftur_t[i] = create_fturet();
    for (int i = 0; i != MAX_PLAT_O; i++)
        make_map->stur_t[i] = create_sturet();
    for (int i = 0; i != MAX_PLAT_O; i++)
        make_map->ttur_t[i] = create_tturet();
    for (int i = 0; i != MAX_PLAT_O; i++)
        make_map->qtur_t[i] = create_qturet();
    for (int i = 0; i != MAX_PLAT_O; i++)
        make_map->platform_t[i] = create_platform();
    for (int i = 0; i != MAX_EN_OO; i++)
        make_map->fenemie_t[i] = create_fenemie();
    for (int i = 0; i != MAX_EN_OD; i++)
        make_map->senemie_t[i] = create_senemie();
    for (int i = 0; i != MAX_EN_OT; i++)
        make_map->tenemie_t[i] = create_tenemie();
    for (int i = 0; i != MAX_PLAT_O; i++)
        make_map->fbulet_t[i] = create_fbulet();
    for (int i = 0; i != MAX_PLAT_O; i++)
        make_map->sbulet_t[i] = create_sbulet();
    for (int i = 0; i != MAX_PLAT_O; i++)
        make_map->tbulet_t[i] = create_tbulet();
    for (int i = 0; i != MAX_PLAT_O; i++)
        make_map->qbulet_t[i] = create_qbulet();
    return make_map;
}

