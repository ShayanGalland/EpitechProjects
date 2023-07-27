/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "functions.h"

void sort_numbers (list* l_a, list* l_b) 
{
    int number_to_find = l_a->size-1;

    while(number_to_find != -1) {
        for(int i = 0; i < l_a->size;i++)
            sort_a(l_a, l_b, i, number_to_find);
        number_to_find--;
    }
    while(l_b->size!=1) {
        rrotate(l_b);
        write(1, "rra ", 4);
        pop_sort(l_a, l_b);
    }
    push(l_b, l_a);
    write(1, "pa\n", 3);   
}

