/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/
#include "functions.h"

int my_putnbr(int nb)
{
    if (nb < 0){
        my_putchar('-');
        nb = -1 * nb;
    }
    if (nb/10) {
        my_putnbr(nb/10);
        my_putchar(nb % 10 + '0');
    }
    if (nb < 10)
        my_putchar(nb + '0');
    return (0);
}
