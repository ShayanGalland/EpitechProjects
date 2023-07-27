/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#ifndef _FUNCTIONS_H
    #define _FUNCTIONS_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <time.h>
    #include "../lib/set.h"
    #include "../lib/stack.h"
    #include "../commons/cell.h"

cell_t **perfect(int x, int y);
void create_maze_perfect(int x, int y, cell_t **map);
cell_t **imperfect(int x, int y);
unsigned int rand_num(int min, int max);
#endif