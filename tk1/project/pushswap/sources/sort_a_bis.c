/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "functions.h"

void sort_a_bis(list *l_a, list *l_b, int rot_left)
{
    for(int i = 0; i < rot_left;i++) {
        rotate(l_a);
        write(1, "ra ", 3);
    }
    push_sort(l_a, l_b);
    for(int i = 0; i < rot_left;i++) {
        rrotate(l_a);
        write(1, "rra ", 4);
    }
}