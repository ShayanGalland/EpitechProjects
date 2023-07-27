/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "functions.h"

list *free_list_struct(list *l_a)
{
    if (l_a) {
        free(l_a->l);
        free(l_a);
    }

    return NULL;
}