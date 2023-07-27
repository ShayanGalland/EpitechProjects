/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "necessary.h"
#include "time.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac == 2) {
        srand(time(NULL));
        display_file(av[1]);
    } else
        return (84);
    return (0);
}
