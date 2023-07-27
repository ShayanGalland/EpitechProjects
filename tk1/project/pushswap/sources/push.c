/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "functions.h"

int push(list *l_a, list *l_b)
{
    if (l_a->size > 0) {
        int va = l_a->l[0];
        for (int i = 0; i < l_a->size; i++)
            l_a->l[i] = l_a->l[i + 1];
        l_a->size--;
        for(int i = l_b->size; i > 0; i--){
            l_b->l[i] = l_b->l[i-1];
        }  
        l_b->l[0] = va;
        l_b->size++;
        return 1;
    }
    return 0;
}