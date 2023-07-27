/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

void print_shoot_result(char x, char y, int result, char ** map) 
{
    char buffer[2];
    buffer[0] = y+65;
    buffer[1] = x+49;
    write(1, buffer, 2);
    write(1, ": ", 2);
    result == 1 ?  write(1, "hit\n\n", 5) :  write(1, "missed\n\n", 8);
    if(result == 0)
        map[x][y] = 'o';
    else
        map[x][y] = 'x';
}