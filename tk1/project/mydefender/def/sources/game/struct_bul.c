/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** main_mydefnder.c
*/

#include "my_defender_game.h"
#include "my_struct.h"

fbulet_t *create_fbulet()
{
    fbulet_t *make_bulet = malloc(sizeof(fbulet_t));

    make_bulet->ftbulet = sfTexture_createFromFile("asset/tour/bulet.png", NULL);
    make_bulet->fbultet = create_sprite(make_bulet->ftbulet);
}

sbulet_t *create_sbulet()
{
    sbulet_t *make_bulet = malloc(sizeof(sbulet_t));

    make_bulet->stbulet = sfTexture_createFromFile("asset/tour/black_bulet.png", NULL);
    make_bulet->sbultet = create_sprite(make_bulet->stbulet);
}

tbulet_t *create_tbulet()
{
    tbulet_t *make_bulet = malloc(sizeof(tbulet_t));

    make_bulet->ttbulet = sfTexture_createFromFile("asset/tour/yellow_bulet.png", NULL);
    make_bulet->tbultet = create_sprite(make_bulet->ttbulet);
}

qbulet_t *create_qbulet()
{
    qbulet_t *make_bulet = malloc(sizeof(qbulet_t));

    make_bulet->qtbulet = sfTexture_createFromFile("asset/tour/energetic_bulet.png", NULL);
    make_bulet->qbultet = create_sprite(make_bulet->qtbulet);
}