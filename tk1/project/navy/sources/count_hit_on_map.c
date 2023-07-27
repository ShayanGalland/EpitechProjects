/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

int count_hit_on_map(char ** my_map)
{
    int my_map_hit = 0;
    for(int x = 0; x < 8; x++) {
        for(int y = 0; y < 8; y++) {
            my_map_hit = hit_on_map(x, y, my_map);
        }
    }
    return my_map_hit;
}
