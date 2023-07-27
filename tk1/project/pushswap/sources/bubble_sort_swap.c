/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "functions.h"

void bubble_sort_swap(list *l_a, int un, int deux ,list *l_b)
{    
    int rot_left = un;
    int rot_right = l_a->size - un;

    if(rot_left < rot_right)
        bubble_sort_swap_left(rot_left, l_a);
    else {
        for(int i = 0; i < rot_right;i++) {
            rrotate(l_a);
            write(1, "rra ", 4);
        }
        swap(l_a);
        write(1, "sa ", 3);
        for(int i = 0; i < rot_right;i++) {
            rotate(l_a);
            write(1, "ra ", 3);
        }
    }
}