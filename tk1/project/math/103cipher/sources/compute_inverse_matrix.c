/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c 103cipher
*/
#include "functions.h"

matrix_t *compute_inverse_matrix(matrix_t *matrix)
{
    matrix_t *inverse_matrix = create_matrix(matrix->nb_rows, matrix->nb_colums);
    if (matrix->nb_colums == 2 && matrix->nb_rows == 2) {
        inverse_matrix->data[0][0] = matrix->data[1][1];
        inverse_matrix->data[0][1] = -matrix->data[0][1];
        inverse_matrix->data[1][0] = -matrix->data[1][0];
        inverse_matrix->data[1][1] = matrix->data[0][0];
        double determinant = compute_determinant(matrix);
        for (int r = 0; r < inverse_matrix->nb_rows; r++) {
            for (int c = 0; c < inverse_matrix->nb_rows; c++)
                inverse_matrix->data[r][c] = 1 * inverse_matrix->data[r][c] / determinant;}}
    else if (matrix->nb_colums == 3 && matrix->nb_rows == 3) {
        double determinant = compute_determinant(matrix);
        for (int r = 0; r < inverse_matrix->nb_rows; r++) {
            for (int c = 0; c < inverse_matrix->nb_rows; c++)
                inverse_matrix->data[r][c] = compute_cofactors_matrix_3(matrix, r, c);}
        matrix_t *transposed_matrix = transpose_matrix(inverse_matrix);
        free_matrix(inverse_matrix);
        for (int r = 0; r < transposed_matrix->nb_rows; r++) {
            for (int c = 0; c < transposed_matrix->nb_rows; c++)
                transposed_matrix->data[r][c] = transposed_matrix->data[r][c] / determinant;}
        return transposed_matrix;}
    else {
        free_matrix(inverse_matrix);
        return NULL;}
    return inverse_matrix;
}
