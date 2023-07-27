/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "functions.h"

void swap(list *l_a)
{
    if(l_a->size > 1) {
        int v = l_a->l[0];
        l_a->l[0] = l_a->l[1]; 
        l_a->l[1] = v;
    }
}


