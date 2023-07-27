/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c 103cipher
*/
#include "functions.h"

matrix_t *create_key_matrix(char *key)
{
    int size_key = strlen(key);
    int min_square = compute_min_perfect_square(size_key);
    int i = 0;
    matrix_t *key_matrix = create_matrix(min_square, min_square);

    for (int r = 0; r != min_square; r++) {
        for (int c = 0; c != min_square; c++) {
            key_matrix->data[r][c] = key[i];
            i++;
            if (i > size_key)
                break;
        }
    }
    return key_matrix;
}