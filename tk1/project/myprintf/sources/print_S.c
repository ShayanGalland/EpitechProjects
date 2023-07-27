/*
** EPITECH PROJECT, 2021
** print_S
** File description:
** y
*/

#include "my.h"

void print_S(const char *str)
{
    while (*str != '\0')
    {
        unsigned char v = *str;

        if(v < 32 || v >= 127){
            my_putchar('\\');
            print_o(v);
        } else {
            my_putchar(v);
        }
        str++;
    }
}
