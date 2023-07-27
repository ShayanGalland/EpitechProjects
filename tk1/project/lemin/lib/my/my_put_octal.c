/*
** EPITECH PROJECT, 2022
** put octal
** File description:
** put octal
*/

#include "my.h"

int my_put_octal(int nb)
{
    int start;
    int end;

    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb);
    } else {
        end = nb % 8;
        start = nb / 10;
        if (start != 0)
            my_put_nbr(start);
        my_putchar(end + '0');
    }
    return (end);
}
