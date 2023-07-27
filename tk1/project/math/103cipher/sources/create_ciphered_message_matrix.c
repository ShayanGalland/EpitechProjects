/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c 103cipher
*/
#include "functions.h"

matrix_t *create_ciphered_message_matrix(char *ciphered_message, int size_key)
{
    int spaces_count = 0;
    for (int i = 0; ciphered_message[i] != '\0'; i++) {
        if (ciphered_message[i] == ' ')
            spaces_count++;
    }
    int size_message = spaces_count + 1;
    int nb_rows = size_message / size_key + (size_message % size_key == 0 ? 0 : 1);
    matrix_t *message_matrix = create_matrix(size_key, nb_rows);
    char *v = strtok(ciphered_message, " ");
    for (int r = 0; r != message_matrix->nb_rows; r++) {
        for (int c = 0; c != message_matrix->nb_colums; c++) {
            message_matrix->data[r][c] = (double)atoi(v);
            v = strtok(NULL, " ");
            if (v == NULL)
                break;
        }
    }
    return message_matrix;
}