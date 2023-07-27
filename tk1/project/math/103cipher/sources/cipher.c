/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c 103cipher
*/
#include "functions.h"

int cipher(char *clear_message, char *key)
{
    matrix_t *key_matrix = create_key_matrix(key);
    matrix_t *message_matrix = create_message_matrix(clear_message, compute_min_perfect_square(strlen(key)));
    matrix_t *ciphered_message_matrix = multiply_matrix(message_matrix, key_matrix);
    free_matrix(key_matrix);
    free_matrix(message_matrix);
    print_matrix(ciphered_message_matrix);
    free_matrix(ciphered_message_matrix);
    return 0;
}
