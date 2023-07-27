/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "functions.h"

void sort_a(list *l_a, list *l_b, int i, int number_to_find)
{
    if(l_a->l[i] == number_to_find) {
        int rot_left = i;
        int rot_right = l_a->size - i;
        if(rot_left < rot_right)
            sort_a_bis(l_a, l_b, rot_left);
        else {
            for(int i = 0; i < rot_right;i++) {
                rrotate(l_a);
                write(1, "rra ", 4);
            }
            push_sort(l_a, l_b);
            for(int i = 0; i < rot_right;i++) {
                rotate(l_a);
                write(1, "ra ", 3);
             }
        }
    }
}