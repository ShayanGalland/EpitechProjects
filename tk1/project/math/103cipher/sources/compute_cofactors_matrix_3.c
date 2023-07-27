/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c 103cipher
*/
#include "functions.h"

double compute_cofactors_matrix_3(matrix_t *matrix, int row, int col)
{
    double a = matrix->data[0][0];
    double b = matrix->data[0][1];
    double c = matrix->data[0][2];
    double d = matrix->data[1][0];
    double e = matrix->data[1][1];
    double f = matrix->data[1][2];
    double g = matrix->data[2][0];
    double h = matrix->data[2][1];
    double i = matrix->data[2][2];

    compute_matrix_letters(row, col, a, b, c, d, e, f, g, h, i);
}