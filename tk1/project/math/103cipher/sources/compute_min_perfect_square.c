/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c 103cipher
*/
#include "functions.h"

int compute_min_perfect_square(int data_len)
{
    for (int i = 1; i < 10000; i++) {
        if (i * i >= data_len)
            return i;
    }
}