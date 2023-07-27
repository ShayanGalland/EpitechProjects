/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** do my_put_nbr
*/

#include<unistd.h>

void my_putchar(char c);

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_nbr(nb/10);
        my_put_nbr(nb % 10);
    } else {
        my_putchar(nb + '0');
    }
}
