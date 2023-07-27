/*
** EPITECH PROJECT, 2021
** reset_buffer
** File description:
** y
*/
#include "functions.h"

void reset_buffer(char *buffer, char val, int size)
{
    for (int i = 0; i < size; i++) {
        buffer[i] = 0;
    }
}
