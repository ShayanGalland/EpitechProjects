/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "functions.h"

int is_sorted(list* l_a){
    int is_sorted = TRUE;
    for(int i = 0; i < l_a->size-1; i++){
        if(l_a->l[i] > l_a->l[i+1]){
            is_sorted = FALSE;
            break;
        }
    }

    return is_sorted;
}