/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c 103cipher
*/
#ifndef _FUNCTION_H
#define _FUNCTION_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "math.h"
struct matrix
{
    int nb_colums;
    int nb_rows;

    double **data;
};
typedef struct matrix matrix_t;
int compute_min_perfect_square(int data_len);
matrix_t *create_matrix(int nb_colums, int nb_rows);
void free_matrix(matrix_t *matrix);
void print_matrix(matrix_t *matrix);
matrix_t *create_key_matrix(char *key);
matrix_t *create_message_matrix(char *message, int size_key);
matrix_t *multiply_matrix(matrix_t *M1, matrix_t *M2);
matrix_t *transpose_matrix(matrix_t *matrix);
matrix_t *compute_inverse_matrix(matrix_t *matrix);
int cipher(char *clear_message, char *key);
int uncipher(char *cipher_message, char *key);
double compute_matrix_letters(int row, int col, double a, double b, double c, double d, double e, double f, double g, double h, double i);
#endif
