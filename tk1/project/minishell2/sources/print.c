/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "../include/functions.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putchar_er(char c)
{
    write(2, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return 0;
}

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

int putstr_er(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar_er(str[i]);
        i = i + 1;
    }
    return 0;
}
