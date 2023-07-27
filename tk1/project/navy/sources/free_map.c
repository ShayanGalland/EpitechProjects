/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

void free_map(char** map)
{
    for(int x = 0; x < 8; x++)
        free(map[x]);
    free(map);
}