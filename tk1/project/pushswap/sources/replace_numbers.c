/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "functions.h"

void replace_numbers(list* l_a)
{
    list copy;
    list copy2;
    int number = 0;
    copy.l = malloc(sizeof(int)*l_a->size);
    copy.size = l_a->size;
    copy2.l = malloc(sizeof(int)*l_a->size);
    copy2.size = l_a->size;
    for(int i = 0; i < l_a->size;i++)
        copy2.l[i] = l_a->l[i];
    sort_a_list(&copy, &copy2, copy.size-1);
    for(int i = 0; i < l_a->size;i++) {
        for(int j = 0; j < l_a->size; j++) {
            if(copy.l[i] == l_a->l[j])
                l_a->l[j] = number;
        }
        number++;
    }
    free(copy.l);
    free(copy2.l);
}
