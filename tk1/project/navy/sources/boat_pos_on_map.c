/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

void boat_pos_on_map(int row_start, int row_end, int col_start, int col_end, char **my_map, int boat_number)
{    
    for(int x = row_start; x < row_end+1;x++) {
        for(int y = col_start; y < col_end+1;y++)
            my_map[x][y] = boat_number+49-1;
    }
}