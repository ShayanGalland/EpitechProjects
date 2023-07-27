/*
** EPITECH PROJECT, 2021
** read_map_line
** File description:
** y
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void read_map_line(int *columns_count, char *current_line, char **map, int i)
{
    *columns_count = my_strlen(current_line);
    map[i] = malloc(sizeof(char) * *columns_count);
    for (int j = 0; j < *columns_count; j++) {
        map[i][j] = current_line[j];
    }
}
