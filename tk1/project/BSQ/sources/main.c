/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** y
*/
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

int main(int argc, char **argv)
{
    if(argc == 1)
        return 84;

    int lines = 0;
    int columns = 0;
    char **map = read_map(argv[1], &lines, &columns);
    if (!map)
        return 84;
    find_max_square(map, lines, columns);
    print_map(map, lines, columns);

    return 0;
}
