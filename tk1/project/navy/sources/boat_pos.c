/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

int boat_pos(char *buffer, int i, char **my_map)
{
int boat_number = -1;
    int row_start = -1;
    int col_start = -1;
    int row_end = -1;
    int col_end = -1;
    while(buffer[i] != '\n' && buffer[i] != '\0') {
        if(buffer[i] != ':') {
            if(boat_number == -1)
                boat_number = buffer[i] - 49 + 1;
            else if(col_start == -1)
                col_start = buffer[i] - 65;
            else if(row_start == -1)
                row_start = buffer[i] - 49;
            else if(col_end == -1)
                col_end = buffer[i] - 65;
            else if(row_end == -1)
                row_end = buffer[i] - 49;
        }
        i++;
    }
    boat_pos_on_map(row_start, row_end, col_start, col_end, my_map, boat_number);
    if(boat_number == 5)
        return 84;
    i++;
    return i;
}