/*
** EPITECH PROJECT, 2022
** my_tablen
** File description:
** QoL+1
*/

#include <stddef.h>

int my_tablen(char **tab)
{
    int n = 0;

    for (n = 0; tab[n] != NULL; n++);
    return n;
}