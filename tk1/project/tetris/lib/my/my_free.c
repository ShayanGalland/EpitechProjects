/*
** EPITECH PROJECT, 2021
** my_free
** File description:
** no i'm not free tonight
*/
#include <stdlib.h>
#include <stddef.h>

void my_free(char **tab)
{
    int n = 0;

    for (n = 0; tab[n] != NULL; n++)
        free(tab[n]);
    free(tab[n]);
    free(tab);
}
