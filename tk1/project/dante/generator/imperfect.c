/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "function.h"

int imperfect_cell(int i, int j, cell_t **map)
{
    int rand = 0;

    if (map[i][j].value != 'X')
        return 0;
    if (!(map[i-1][j].value == '*' && map[i+1][j].value == '*' &&
     map[i][j-1].value == 'X' && map[i][j+1].value == 'X' ))
        return 0;
    rand = rand_num(0, 100);
    if (rand < 20)
        map[i][j].value = '*';
    return 1;
}

cell_t **imperfect(int x, int y)
{
    cell_t **map = perfect(x, y);

    for (int i = 1; i < x-1;i++) {
        for (int j = 1; j < y-1; j++)
            imperfect_cell(i,j, map);
    }
    return map;
}