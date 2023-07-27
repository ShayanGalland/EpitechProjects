/*
** EPITECH PROJECT, 2023
** project
** File description:
** in c
*/

#include "functions.h"

void array_1d_to_2d(const int *array , size_t height ,
size_t width , int ***res)
{
    int **twod_array = NULL;
    int n = 0;

    twod_array = malloc(sizeof(int *) * height);
    for (long unsigned int i = 0; i < height; i++)
        twod_array[i] = malloc(sizeof(int) * width);
    for (long unsigned int j = 0; j < height; j++) {
        for (long unsigned int i = 0; i < width; i++) {
            twod_array[j][i] = array[n];
            n++;
        }
    }
    *res = twod_array;
}

void array_2d_free(int **array , size_t height , size_t width)
{
    for (long unsigned int j = 0; j < height; j++)
        free(array[j]);
    free(array);
    width = width;
}