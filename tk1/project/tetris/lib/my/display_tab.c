/*
** EPITECH PROJECT, 2022
** display_tab
** File description:
** my_puttab
*/

#include <stddef.h>
#include <unistd.h>

int my_strlen(char *str);

void display_tab(char **tab)
{
    for (int n = 0; tab[n] != NULL; n++)
        write(1, &tab[n], my_strlen(tab[n]));
}
