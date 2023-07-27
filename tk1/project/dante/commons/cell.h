/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#ifndef _CELL_H
    #define _CELL_H
    #include <stdlib.h>

struct cell {
    int x;
    int y;
    char value;
    void *prev;
};
typedef struct cell cell_t;

cell_t **create_cells(int x, int y);
int compare_cell(void *a, void *b);

#endif