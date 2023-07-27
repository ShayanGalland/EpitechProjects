/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** main_mydefnder.c
*/

#include "my_defender_game.h"
#include "my.h"

tour_t *create_tower()
{
    tour_t *make_tour = malloc(sizeof(tour_t));

    make_tour->fprice = sfFont_createFromFile("asset/txt/font.ttf");
    make_tour->price = sfText_create();
    make_tour->validate_o = 0;
    make_tour->validate_d = 0;
    make_tour->validate_t = 0;
    make_tour->validate_q = 0;
    make_tour->time_t = 0;
    make_tour->set = 0;
    make_tour->one = 0;
    make_tour->two = 0;
    make_tour->tree = 0;
    make_tour->four = 0;
    make_tour->set_o = malloc(sizeof(int)*MAX_PLAT_O);
    make_tour->set_d = malloc(sizeof(int)*MAX_PLAT_O);
    make_tour->set_t = malloc(sizeof(int)*MAX_PLAT_O);
    make_tour->set_q = malloc(sizeof(int)*MAX_PLAT_O);
    make_tour->fturet_posed = malloc(sizeof(int)*MAX_PLAT_O);
    make_tour->sturet_posed = malloc(sizeof(int)*MAX_PLAT_O);
    make_tour->tturet_posed = malloc(sizeof(int)*MAX_PLAT_O);
    make_tour->qturet_posed = malloc(sizeof(int)*MAX_PLAT_O);
    for (int i = 0; i != MAX_PLAT_O; i++)
        make_tour->fturet_posed[i] = 0;
    for (int i = 0; i != MAX_PLAT_O; i++)
        make_tour->sturet_posed[i] = 0;
    for (int i = 0; i != MAX_PLAT_O; i++)
        make_tour->tturet_posed[i] = 0;
    for (int i = 0; i != MAX_PLAT_O; i++)
        make_tour->qturet_posed[i] = 0;
    return make_tour;
}

ftur_t *create_fturet()
{
    ftur_t *make_ftur = malloc(sizeof(ftur_t));

    make_ftur->tt_o = sfTexture_createFromFile("asset/tour/tour1.png", NULL);
    make_ftur->t_o = create_sprite(make_ftur->tt_o);
}

stur_t *create_sturet()
{
    stur_t *make_stur = malloc(sizeof(stur_t));

    make_stur->tt_d = sfTexture_createFromFile("asset/tour/tour2.png", NULL);
    make_stur->t_d = create_sprite(make_stur->tt_d);
}

ttur_t *create_tturet()
{
    ttur_t *make_ttur = malloc(sizeof(ttur_t));

    make_ttur->tt_t = sfTexture_createFromFile("asset/tour/tour3.png", NULL);
    make_ttur->t_t = create_sprite(make_ttur->tt_t);
}

qtur_t *create_qturet()
{
    qtur_t *make_qtur = malloc(sizeof(qtur_t));

    make_qtur->tt_q = sfTexture_createFromFile("asset/tour/tour4.png", NULL);
    make_qtur->t_q = create_sprite(make_qtur->tt_q);
}
