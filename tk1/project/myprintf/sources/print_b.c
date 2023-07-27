/*
** EPITECH PROJECT, 2021
** print_b
** File description:
** y
*/
#include "my.h"

void print_b(unsigned int number)
{
    unsigned char* bytes = (unsigned char*) &number;
    int bytes_len = sizeof(number);

    for(int i = bytes_len-1; i >= 0; i--) {
        for(int j = 7; j >= 0; j--) {
            my_putchar(((bytes[i] >> j) & 1) ? '1' : '0');
        }
        my_putchar(' ');
    }
}
