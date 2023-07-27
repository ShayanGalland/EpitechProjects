/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "functions.h"

void bubble_sort(list *l_a, list *l_b)
{
    for(int i = l_a->size; i > 0; i--) {
        int sorted = 1;
        for(int j = 0; j < i-1; j++) {
            if(l_a->l[j+1] < l_a->l[j]) {
                bubble_sort_swap(l_a, j, j+1 ,l_b);
                sorted = 0;
            }
        }
        if(sorted == 1)
            break;
    }
}