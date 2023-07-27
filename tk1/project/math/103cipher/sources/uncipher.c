/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c 103cipher
*/
#include "functions.h"

int uncipher(char *cipher_message, char *key)
{
    matrix_t *key_matrix = create_key_matrix(key);
    matrix_t *message_matrix = create_ciphered_message_matrix(cipher_message, compute_min_perfect_square(strlen(key)));
    matrix_t *inverse_matrix = compute_inverse_matrix(key_matrix);
    free_matrix(key_matrix);
    matrix_t *ciphered_message_matrix = multiply_matrix(message_matrix, inverse_matrix);
    free_matrix(message_matrix);
    free_matrix(inverse_matrix);
    for (int r = 0; r != ciphered_message_matrix->nb_rows; r++) {
        for (int c = 0; c != ciphered_message_matrix->nb_colums; c++)
            printf("%c", (char)(ciphered_message_matrix->data[r][c]));
    }
    printf("\n");
    free_matrix(ciphered_message_matrix);
    return 0;
}