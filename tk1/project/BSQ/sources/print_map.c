/*
** EPITECH PROJECT, 2021
** print_map.c
** File description:
** y
*/
#include "functions.h"

void print_map(char** map, int lines, int columns)
{
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            my_putchar(map[i][j]);
        }
        my_putchar('\n');
    }
}
