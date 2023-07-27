/*
** EPITECH PROJECT, 2021
** emacs
** File description:
** emacs
*/
#include "my.h"

void print_xx_bis(long x, unsigned int number, char *hexa, int n)
{
    while (number != 0) {
        x = number % 16;
        if (x < 10) {
            n++;
            hexa[n] = 48 + x;
        }
        if (x >= 10) {
            n++;
            hexa[n] = 55 + x;
        }
        number /= 16;
    }
    for (int i = n; i >= 0; i--)
        my_putchar(hexa[i]);
    free(hexa);
}