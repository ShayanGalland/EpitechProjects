/*
** EPITECH PROJECT, 2022
** init_disp.c
** File description:
** init_disp.c
*/

#include "necessary.h"
#include <stddef.h>
#include <stdlib.h>
#define SIZE 50

void init_displ(char *star, int tries)
{
    my_putstr(star);
    my_putstr("\n\n");
    my_putstr("Round ");
    my_put_nbr(tries);
    my_putstr("\n");
    my_putstr(">");
}

void end_disp(int tries)
{
    my_putstr("\n\n");
    my_putstr("Round ");
    my_put_nbr(tries);
    my_putstr("\n");
    my_putstr(">");
}

int find_word(char *str, char *str2, int n)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == str2[i] && n == 0)
            return (i);
        if (str[i] == str2[i])
            n--;
    }
    return (-1);
}

void fill_star(int n, char *my_string, char *tab, char *star)
{
    for (int i = 0; i < SIZE; i++) {
        if (find_letter(tab, my_string[n], i) >= 0)
            star[find_letter(tab, my_string[n], i)] = '?';
    }
    for (int i = 0; i < SIZE; i++) {
        if (find_word(my_string, tab, i) >= 0)
            star[find_word(my_string, tab, i)] =
            tab[find_word(my_string, tab, i)];
    }

}

void extend_dis(char *my_string, char **tab, char *star, int numbers)
{
    for (int n = 0; n < my_strlen(my_string); n++)
        fill_star(n, my_string, tab[numbers], star);
}
