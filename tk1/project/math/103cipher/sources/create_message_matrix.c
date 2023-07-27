/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c 103cipher
*/
#include "functions.h"

matrix_t *create_message_matrix(char *message, int size_key)
{
    int size_message = strlen(message);
    int nb_rows = size_message / size_key + (size_message % size_key == 0 ? 0 : 1);
    int i = 0;
    matrix_t *message_matrix = create_matrix(size_key, nb_rows);

    for (int r = 0; r != message_matrix->nb_rows; r++) {
        for (int c = 0; c != message_matrix->nb_colums; c++) {
            message_matrix->data[r][c] = message[i];
            i++;
            if (i > size_message)
                break;
        }
    }
    return message_matrix;
}