/*
** EPITECH PROJECT, 2021
** mem_alloc_2d_array
** File description:
** mem_alloc_2d_array
*/

#include "necessary.h"
#include <stdlib.h>

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **result;
    int i = 0;

    result = malloc(sizeof(char*) * nb_rows + 1);
    for (i = 0; i < nb_rows; i++)
        result[i] = malloc(sizeof(char) * nb_cols + 1);
    return (result);
}
