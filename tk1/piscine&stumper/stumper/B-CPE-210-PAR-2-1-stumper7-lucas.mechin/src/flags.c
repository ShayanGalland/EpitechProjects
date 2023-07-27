/*
** EPITECH PROJECT, 2022
** flags
** File description:
** flags
*/

#include "necessary.h"
#include "string.h"

void flags(int ac, char **av, char_t *mem_char)
{
    if (av[1][0] == '-' && av[1][1] == 't') {
        mem_char->status = 2;
        count_char(av[2], mem_char);
    }
    else if (av[1][0] == '-' && av[1][1] == 'r') {
        mem_char->status = 1;
        count_char(av[2], mem_char);
    }
    if (ac == 2) {
        mem_char->status = 0;
        count_char(av[1], mem_char);
    }
    if (ac == 3) {
        mem_char->status = 3;
        double_str(av[1], av[2], mem_char);
    }
}
