/*
** EPITECH PROJECT, 2021
** init_matrix
** File description:
** y
*/
#include "functions.h"

void init_matrix(char **M, int **S, int lines, int columns)
{
    for (int i = 0; i < lines; i++)
        S[i][0] = M[i][0] == '.' ? 1 : 0;
    for (int j = 0; j < columns; j++)
        S[0][j] = M[0][j] == '.' ? 1 : 0;
    for (int i = 1; i < lines; i++) {
        for (int j = 1; j < columns; j++) {
            if (M[i][j] == '.')
                S[i][j] = min_three(S[i][j - 1], S[i - 1][j], S[i - 1][j - 1]) + 1;
            else
                S[i][j] = 0;
        }
    }
}
