/*
** EPITECH PROJECT, 2021
** print_suqare_in_map
** File description:
** y
*/
#include "functions.h"

void print_square_in_map(char** M, int max_i, int max_j, int max_of_s){
    for (int i = max_i; i > max_i - max_of_s; i--) {
        for (int j = max_j; j > max_j - max_of_s; j--) {
            M[i][j] = 'x';
        }
    }
}
