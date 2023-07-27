/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** main_mydefnder.c
*/

#include "my_defender_game.h"
#include "my.h"

platform_t *create_platform()
{
    platform_t *make_platform = malloc(sizeof(platform_t));

    make_platform->tplt = sfTexture_createFromFile("asset/platform.png", NULL);
    make_platform->plt = create_sprite(make_platform->tplt);

}
