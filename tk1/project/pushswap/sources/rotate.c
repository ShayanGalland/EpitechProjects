/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "functions.h"

void rotate(list* l_a)
{
    int vfirst = l_a->l[0];
    for(int i = 0; i < l_a->size;i++)
        l_a->l[i] = l_a->l[i+1];
    l_a->l[l_a->size-1] = vfirst;
}
