/*
** EPITECH PROJECT, 2021
** print_X
** File description:
** y
*/

#include "my.h"

void print_xx(unsigned int number)
{
    long x = 0;
    int l = 1;
    int n = 0;
    if (number < my_compute_power_it(10, l))
        l++;
    char *hexa = malloc(sizeof(char)*(l+2));
    print_xx_bis(x, number, hexa, n);
}