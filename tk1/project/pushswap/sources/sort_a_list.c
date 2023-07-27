/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "functions.h"

void sort_a_list(list *copy, list *copy2, int last)
{
    int smaller = 0;

    for (int i = 0; i != copy->size;i++) {
        smaller = find_smaller(copy2, last);
        copy->l[i] = copy2->l[smaller];
        copy2->l[smaller] = copy2->l[last];
        last--;
    }
}