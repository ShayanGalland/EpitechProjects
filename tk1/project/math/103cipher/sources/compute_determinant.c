/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c 103cipher
*/
#include "functions.h"

int compute_determinant(matrix_t *matrix)
{
    if (matrix->nb_colums == 2 && matrix->nb_rows == 2)
        return matrix->data[0][0] * matrix->data[1][1] - matrix->data[0][1] * matrix->data[1][0];
    else if (matrix->nb_colums == 3 && matrix->nb_rows == 3) {
        double A = compute_cofactors_matrix_3(matrix, 0, 0);
        double B = compute_cofactors_matrix_3(matrix, 0, 1);
        double C = compute_cofactors_matrix_3(matrix, 0, 2);
        return matrix->data[0][0] * A + matrix->data[0][1] * B + matrix->data[0][2] * C;
    }
    else
        return 0;
}