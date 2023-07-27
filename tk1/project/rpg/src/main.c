/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "include.h"

sfSprite *init_sprite(sfTexture *texture)
{
    sfSprite *mySprite = sfSprite_create();
    sfSprite_setTexture(mySprite, texture, 0);
    return mySprite;
}

int main(int ac, char **av)
{
    ac = ac;
    av = av;
    my_rpg();
    return 0;
}
