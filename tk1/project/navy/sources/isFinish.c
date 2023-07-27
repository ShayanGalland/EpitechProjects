/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

int isFinish(char ** my_map, char ** their_map)
{
    int my_map_hit = count_hit_on_map(my_map);
    int their_map_hit = count_hit_on_map(their_map);
    if(my_map_hit == 14) {
        write(1, "Enemy won\n", 11);
        return 1;
    } 
    else if(their_map_hit == 14) {
        write(1, "I won\n", 7);
        return 1;
    } 
    else
        return 0;
}