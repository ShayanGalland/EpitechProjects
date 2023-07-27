/*
** EPITECH PROJECT, 2021
** emacs
** File description:
** emacs
*/
#include "my.h"

unsigned int my_compute_power_it(int nb, int p)
{
    int result;

    if (p == 0)
        return (1);
    if (p == 1)
        return nb;
    if (p < 0)
        return (0);
    while ((p - 1) != 0) {
        result = nb * nb;
        p--;
    }
    return (result);
}