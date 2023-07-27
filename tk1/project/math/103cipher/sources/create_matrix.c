/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c 103cipher
*/
#include "functions.h"

matrix_t *create_matrix(int nb_colums, int nb_rows)
{
    matrix_t *matrix = malloc(sizeof(matrix_t));
    matrix->nb_colums = nb_colums;
    matrix->nb_rows = nb_rows;
    matrix->data = (double **)malloc(sizeof(double *) * nb_rows);
    for (int i = 0; i < nb_rows; i++) {
        matrix->data[i] = malloc(sizeof(double) * nb_colums);
        memset(matrix->data[i], 0, sizeof(double) * nb_colums);
    }
    return matrix;
}