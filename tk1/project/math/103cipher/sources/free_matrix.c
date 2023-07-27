/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c 103cipher
*/
#include "functions.h"

void free_matrix(matrix_t *matrix)
{
    for (int i = 0; i < matrix->nb_rows; i++)
        free(matrix->data[i]);
    free(matrix->data);
    free(matrix);
}
