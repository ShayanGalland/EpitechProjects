/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c 103cipher
*/
#include "functions.h"

matrix_t *transpose_matrix(matrix_t *matrix)
{
    matrix_t *transposed_matrix = create_matrix(matrix->nb_rows, matrix->nb_colums);
    for (int r = 0; r < matrix->nb_rows; r++) {
        for (int c = 0; c < matrix->nb_colums; c++)
            transposed_matrix->data[c][r] = matrix->data[r][c];
    }
    return transposed_matrix;
}