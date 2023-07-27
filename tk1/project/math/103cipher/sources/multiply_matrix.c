/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c 103cipher
*/
#include "functions.h"

matrix_t *multiply_matrix(matrix_t *M1, matrix_t *M2)
{
    matrix_t *matrix_result = create_matrix(M2->nb_colums, M1->nb_rows);
    for (int r = 0; r < matrix_result->nb_rows; r++) {
        for (int c = 0; c < matrix_result->nb_colums; c++) {
            double result = 0;
            for (int i = 0; i < M1->nb_colums; i++)
                result += M1->data[r][i] * M2->data[i][c];
            matrix_result->data[r][c] = round(result);
        }
    }
    return matrix_result;
}