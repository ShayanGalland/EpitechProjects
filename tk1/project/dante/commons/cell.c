/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "cell.h"

int compare_cell(void *a, void *b)
{
    cell_t *c1 = (cell_t*)a;
    cell_t *c2 = (cell_t*)b;

    if (c1->x == c2->x && c1->y == c2->y)
        return 1;
    else
        return 0;
}

cell_t **create_cells(int x, int y)
{
    cell_t **map = NULL;

    map = malloc(sizeof(cell_t*)*x);
    for (int i = 0; i < x; i++) {
        map[i] = malloc(sizeof(cell_t)*y);
        for (int j = 0; j < y; j++) {
            map[i][j].value = 'X';
            map[i][j].x = i;
            map[i][j].y = j;
        }
    }
    return map;
}