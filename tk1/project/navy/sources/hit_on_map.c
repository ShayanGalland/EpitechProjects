/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

int hit_on_map(int x, int y, char **my_map)
{
    int my_map_hit = 0;
    if(my_map[x][y] == 'x')
        my_map_hit++;
    return my_map_hit;
}