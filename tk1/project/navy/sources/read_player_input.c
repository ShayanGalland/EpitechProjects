/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

void read_player_input(char* x, char* y) 
{
    while(1) {
        write(1, "attack: ", 8);
        char * line = NULL;
        size_t len = 0;
        size_t read = 0;
        read = getline(&line, &len, stdin);
        if(read != 3) {
            write(1, "wrong position\n", 16);
            continue;
        }  
        *x = line[1] - 49;
        *y = line[0] - 65;
        free(line);
        if( !(*x > - 1 && *x < 8 && *y > -1 && *y < 8 )) {
            write(1, "wrong position\n", 16);
            continue;
        } 
        else
            break;
    }
}