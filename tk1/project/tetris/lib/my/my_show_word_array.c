/*
** EPITECH PROJECT, 2021
** my_show_word_array
** File description:
** my_puttab
*/

#include <stddef.h>

void my_putchar(char c);

void my_putstr(char *str);

int my_show_word_array(char *const *tab)
{
    for (int n = 0; tab[n] != NULL; n++) {
        my_putstr(tab[n]);
        my_putchar('\n');
    }
    return 0;
}
