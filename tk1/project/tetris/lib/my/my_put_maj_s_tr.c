/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** why must you const antly torture me with this?
*/

#include <stdlib.h>

void my_putchar(char c);

void my_put_octal(int nb);

void my_put_maj_s_tr(char const *str)
{
    for (int n = 0; str[n] != '\0'; n++)
        if (str[n] >= 32 && str[n] < 127)
            my_putchar(str[n]);
        else {
            my_putchar('\\');
            my_put_octal(str[n]);
        }
}
