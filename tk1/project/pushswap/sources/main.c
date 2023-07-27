/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "functions.h"

int main(int argc, char **argv)
{
    list *l_a = create_list_struct(argc - 1);
    list *l_b = create_list_struct(argc - 1);
    l_b->size = 0;

    if (l_a && l_b) {
        for (int i = 0; i < argc - 1; i++)
            l_a->l[i] = my_getnbr(argv[i + 1]);
        if (is_sorted(l_a))
            my_putchar('\n');
        else {
            replace_numbers(l_a);
            sort_numbers(l_a, l_b);
        }
        free_list_struct(l_a);
        free_list_struct(l_b);
    }
}