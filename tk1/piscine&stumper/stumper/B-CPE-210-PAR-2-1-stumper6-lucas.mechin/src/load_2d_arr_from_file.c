/*
** EPITECH PROJECT, 2021
** load_2d_arr_from_file
** File description:
** load_2d_arr_from_file
*/

#include "necessary.h"
#include <stddef.h>

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols)
{
    char *buffer = load_file_in_mem(filepath);
    char **map = NULL;
    int nb = 0;
    int x = 0;
    int y = 0;

    map = mem_alloc_2d_array(nb_rows, nb_cols);
    for (y = 0; y < nb_rows; y++) {
        for (x = 0; x < nb_cols; x++) {
            map[y][x] = buffer[nb];
            nb++;
        }
        map[y][x] = '\0';
        nb++;
    }
    return (map);
}
