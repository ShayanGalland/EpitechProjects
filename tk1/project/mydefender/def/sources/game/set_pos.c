/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** main_mydefnder.c
*/

#include "my_defender_game.h"
#include "my.h"


void map_pos_bis(map_t *map_t, game_t *d)
{
    sfSprite_setPosition(map_t->move_t->rp, start_point(1780, 920));
    sfSprite_setPosition(map_t->move_t->gp, start_point(1840, 180));
    sfSprite_setScale(map_t->coin, start_point(0.18f, 0.18f));
    sfSprite_setPosition(map_t->coin, start_point(1120, 20));
    sfSprite_setScale(map_t->life, start_point(0.14f, 0.14f));
    sfSprite_setPosition(map_t->life, start_point(1500, 25));
}

void map_pos(map_t *map_t, game_t *d)
{
    sfSprite_setPosition(map_t->mp_o, start_point(0, -50));
    sfSprite_setPosition(map_t->mp_d, start_point(0, -50));
    sfSprite_setPosition(map_t->mp_t, start_point(0, -50));
    sfSprite_setScale(map_t->mp_bo, start_point(1.75f, 1.75f));
    sfSprite_setPosition(map_t->mp_bo, start_point(80, 20));
    for (int i = 0;i != MAX_EN_OO;i++) {
        sfSprite_setPosition(map_t->fenemie_t[i], start_point(2000, generate_random_number(190, 230)));
        sfSprite_setScale(map_t->fenemie_t[i], start_point(0.40f, 0.40f));
    }
    for (int i = 0;i != MAX_EN_OD;i++) {
        sfSprite_setPosition(map_t->senemie_t[i], start_point(2000, generate_random_number(190, 230)));
        sfSprite_setScale(map_t->senemie_t[i], start_point(0.50f, 0.50f));
    }
    for (int i = 0;i != MAX_EN_OT;i++) {
        sfSprite_setPosition(map_t->tenemie_t[i], start_point(2000, generate_random_number(190, 230)));
        sfSprite_setScale(map_t->tenemie_t[i], start_point(0.60f, 0.60f));
    }
    for (int i = 0; i != MAX_PLAT_O; i++) {
        sfSprite_setOrigin(map_t->ftur_t[i], start_point(30, 30));
        sfSprite_setOrigin(map_t->stur_t[i], start_point(30, 30));
        sfSprite_setOrigin(map_t->ttur_t[i], start_point(30, 30));
        sfSprite_setOrigin(map_t->qtur_t[i], start_point(30, 30));
        sfSprite_setPosition(map_t->ftur_t[i], start_point(200, 110));
        sfSprite_setScale(map_t->ftur_t[i], start_point(1.35f, 1.35f));
        sfSprite_setPosition(map_t->stur_t[i], start_point(200, 340));
        sfSprite_setScale(map_t->stur_t[i], start_point(1.35f, 1.35f));
        sfSprite_setPosition(map_t->ttur_t[i], start_point(200, 570));
        sfSprite_setScale(map_t->ttur_t[i], start_point(1.35f, 1.35f));
        sfSprite_setPosition(map_t->qtur_t[i], start_point(225, 800));
        sfSprite_setScale(map_t->qtur_t[i], start_point(1.35f, 1.35f));
    }
}

void ground_pos_o_bis(map_t *map_t, game_t *d)
{
    sfSprite_setPosition(map_t->platform_t[12], start_point(1140, 480));
    sfSprite_setPosition(map_t->platform_t[13], start_point(1350, 470));
    sfSprite_setPosition(map_t->platform_t[14], start_point(1530, 470));
    sfSprite_setPosition(map_t->platform_t[15], start_point(1710, 470));
    sfSprite_setPosition(map_t->platform_t[16], start_point(850, 780));
    sfSprite_setPosition(map_t->platform_t[17], start_point(1100, 780));
    sfSprite_setPosition(map_t->platform_t[18], start_point(1100, 630));
    sfSprite_setPosition(map_t->platform_t[19], start_point(1650, 700));
    sfSprite_setPosition(map_t->platform_t[20], start_point(1370, 700));
    sfSprite_setPosition(map_t->platform_t[21], start_point(1650, 850));
    sfSprite_setPosition(map_t->platform_t[22], start_point(1370, 850));
}

void ground_pos_o(map_t *map_t, game_t *d)
{
    for (int i = 0; i < MAX_PLAT_O; i++)
        sfSprite_setScale(map_t->platform_t[i], start_point(0.75f, 0.75f));

    sfSprite_setPosition(map_t->platform_t[0], start_point(1080, 245));
    sfSprite_setPosition(map_t->platform_t[1], start_point(900, 245));
    sfSprite_setPosition(map_t->platform_t[2], start_point(720, 245));
    sfSprite_setPosition(map_t->platform_t[3], start_point(540, 245));
    sfSprite_setPosition(map_t->platform_t[4], start_point(1385, 295));
    sfSprite_setPosition(map_t->platform_t[5], start_point(1565, 295));
    sfSprite_setPosition(map_t->platform_t[6], start_point(1745, 295));
    sfSprite_setPosition(map_t->platform_t[7], start_point(600, 480));
    sfSprite_setPosition(map_t->platform_t[8], start_point(600, 630));
    sfSprite_setPosition(map_t->platform_t[9], start_point(600, 780));
    sfSprite_setPosition(map_t->platform_t[10], start_point(780, 480));
    sfSprite_setPosition(map_t->platform_t[11], start_point(960, 480));

}

void set_all_pos(map_t *map_t, game_t *d)
{
    ground_pos_o(map_t, d);
    ground_pos_o_bis(map_t, d);
    map_pos(map_t, d);
    map_pos_bis(map_t, d);
    map_t->sound_tir = init_sound("asset/musics/shoot1.ogg");
    map_t->sound_bolet = init_sound("asset/musics/bolet.ogg");
    sfSound_setVolume(map_t->sound_tir, 100);
}