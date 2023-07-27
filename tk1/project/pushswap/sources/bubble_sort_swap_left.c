/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "functions.h"

void bubble_sort_swap_left(int rot_left, list *l_a)
{
        for(int i = 0; i < rot_left;i++) {
            rotate(l_a);
            write(1, "ra ", 3);
        }
        swap(l_a);
        write(1, "sa ", 3);
        for(int i = 0; i < rot_left;i++) {
            rrotate(l_a);
            write(1, "rra ", 4);
        }
}