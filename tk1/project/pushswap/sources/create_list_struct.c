/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "functions.h"

list *create_list_struct(int size)
{
    list *l_a = malloc(sizeof(list));
    if (l_a) {
        l_a->size = size;
        l_a->l = malloc(sizeof(int) * size);
        for (int i = 0; i < size - 1; i++)
            l_a->l[i] = 0;

        return l_a;
    }
    else
        return NULL;
}