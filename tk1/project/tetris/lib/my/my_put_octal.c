/*
** EPITECH PROJECT, 2021
** my_put_octal.c
** File description:
** why must you const antly torture me with this?
*/

#include <stdlib.h>

void my_putstr(char *str);

void my_put_octal(int nb)
{
    char *str = malloc(4 * sizeof(char));

    for (int n = 0; n != 3; n++)
        str[n] = '0';
    while (nb != 0) {
        nb--;
        str[2]++;
        if (str[2] > '7') {
            str[2] -= 8;
            str[1]++;
        }
        if (str[1] > '7') {
            str[1] -= 8;
            str[0]++;
        }
    }
    my_putstr(str);
    free (str);
}
