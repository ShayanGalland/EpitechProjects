/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

char** create_map()
{
    char **my_map = malloc(sizeof(char*) * 8);
    for(int x = 0; x < 8; x++) {
        my_map[x] = malloc(sizeof(char) * 8);
        for(int y = 0; y < 8; y++) {
            my_map[x][y] = '.';
        }
    }
    return my_map;
}