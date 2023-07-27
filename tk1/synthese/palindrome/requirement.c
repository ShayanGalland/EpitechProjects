/*
** EPITECH PROJECT, 2021
** synthese
** File description:
** synthese project
*/

#include <stdlib.h>
#include <stdio.h>

int my_factrec_synthesis(int nb)
{
    if (nb == 0 || nb == 1)
        return 1;
    if (nb < 0 || nb > 12)
        return 0;
    return nb * my_factrec_synthesis(nb - 1);
}

int my_squareroot_synthesis(int nb)
{
    for (int n = 0; n <= nb; n++) {
        if ((n * n) == nb)
            return n;
    }
    return -1;
}
