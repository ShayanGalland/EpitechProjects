/*
** EPITECH PROJECT, 2021
** read_map
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

char **read_map(char *map_path, int *lines_count, int *columns_count)
{
    char *buffer = read_map_file(map_path);
    if (!buffer)
        return NULL;
    char current_line[256];
    char **map = NULL;
    int i = 0;
    for (char *buffer_it = buffer; *buffer_it != '\0';) {
        int char_counts = read_line(buffer_it, current_line);
        buffer_it += char_counts;
        if (*lines_count == 0)
            read_lines_count(lines_count, current_line, &map);
        else {
            read_map_line(columns_count, current_line, map, i);
            i++;
        }
    }
    free(buffer);
    return map;
}
