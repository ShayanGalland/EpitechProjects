/*
** EPITECH PROJECT, 2021
** find_max_square
** File description:
** y
*/
#include <stdlib.h>
#include "functions.h"

void find_max_square(char **M, int lines, int columns)
{
    int **S = (int **)malloc(sizeof(int *) * lines);
    for (int y = 0; y < lines; y++)
        S[y] = (int *)malloc(sizeof(int) * columns);
    int max_i  = 0;
    int max_j  = 0;
    init_matrix(M, S, lines, columns);
    int max_of_s  = S[0][0];
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            if (max_of_s < S[i][j]) {
                max_of_s = S[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    print_square_in_map(M, max_i, max_j, max_of_s);
}