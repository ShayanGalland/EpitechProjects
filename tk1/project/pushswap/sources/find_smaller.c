/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "functions.h"

int find_smaller(list *l_a, int last)
{
    int smaller = 0;
    int der = 0;
    int dev = 1;

    for (int n = 0;n != last;n++) {
        if (l_a->l[dev] <= l_a->l[der] && l_a->l[dev] <= l_a->l[smaller]) {
            smaller = dev;
            dev++;
            der++;
        }
        else {
            dev++;
            der++;
        }
    }
    return smaller;
}