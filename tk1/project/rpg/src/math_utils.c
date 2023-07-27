/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "include.h"

float distance(sfSprite *sprite1, sfSprite *sprite2)
{
    float distance = 0;
    float deferent_y = 0;
    float deferent_x = 0;
    sfVector2f P_sprite1 = sfSprite_getPosition(sprite1);
    sfVector2f P_sprite2 = sfSprite_getPosition(sprite2);

    deferent_x = P_sprite1.x - P_sprite2.x;
    deferent_y = P_sprite1.y - P_sprite2.y;
    distance = deferent_x * deferent_x + deferent_y * deferent_y;
    distance = sqrt(distance);
    return (distance);
}

sfVector2f start_point(float x, float y)
{
    sfVector2f point;

    point.y = y;
    point.x = x;
    return point;
}

int generate_random_number(int min, int max)
{
    int result  = rand() % ((max + 1) - min) + min;

    return result;
}