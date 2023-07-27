/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

void print_map(char ** map) 
{
   write(1, " |A B C D E F G H\n", 18);
   write(1, "-+---------------\n", 18);
   for(int x = 0; x < 8; x++) {
       char c = x+49;
       write(1, &c, 1);
       write(1, "|", 1);
       for(int y = 0; y < 8; y++) {
            write(1, &map[x][y], 1);
            if(y != 7)
                write(1, " ", 1);
       }
       write(1, "\n", 1);
   }
}