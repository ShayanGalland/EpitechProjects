/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c 103cipher
*/
#include "functions.h"

double compute_matrix_letters(int row, int col, double a, double b, double c, double d, double e, double f, double g, double h, double i)
{
    if (row == 0 && col == 0)
        return e * i - f * h;
    if (row == 0 && col == 1)
        return -(d * i - f * g);
    if (row == 0 && col == 2)
        return d * h - e * g;
    if (row == 1 && col == 0)
        return -(b * i - c * h);
    if (row == 1 && col == 1)
        return a * i - c * g;
    if (row == 1 && col == 2)
        return -(a * h - b * g);
    if (row == 2 && col == 0)
        return b * f - c * e;
    if (row == 2 && col == 1)
        return -(a * f - c * d);
    if (row == 2 && col == 2)
        return a * e - b * d;
}