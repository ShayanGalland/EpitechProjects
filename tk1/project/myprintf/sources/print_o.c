/*
** EPITECH PROJECT, 2021
** print_o.c
** File description:
** y
*/

#include "my.h"

void print_o(unsigned int nb)
{
    int octet = 0;
    int i = 1;

    while (nb != 0) {
        octet += (nb % 8) * i;
        nb /= 8;
        i *= 10;
    }
    print_d(octet);
}
