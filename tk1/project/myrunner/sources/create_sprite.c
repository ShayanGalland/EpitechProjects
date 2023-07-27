/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** project in c
*/
#include "function.h"

sfSprite *create_sprite(sfTexture *texture)
{
    sfSprite *mySprite = sfSprite_create();
    sfSprite_setTexture(mySprite, texture, 0);
    return mySprite;
}