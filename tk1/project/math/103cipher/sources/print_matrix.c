/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c 103cipher
*/
#include "functions.h"

void print_matrix(matrix_t *matrix)
{
    for (int r = 0; r != matrix->nb_rows; r++) {
        for (int c = 0; c != matrix->nb_colums; c++)
            printf("%d ", (int)(matrix->data[r][c]));
    }
    printf("\n");
}