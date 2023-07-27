/*
** EPITECH PROJECT, 2020
** my_split
** File description:
** Take a string and cut it into little pieces and "voila"
*/

#include "stdlib.h"

int my_strlen(char *str);

static int divide(char *str, char s)
{
    int x = 1;

    for (int n = 0; str[n] != '\0'; n++)
        if (str[n] == s)
            x++;
    return x;
}

char **my_split(char **tab, char *str, char s)
{
    tab = malloc((divide(str, s) + 1) * sizeof(char *));
    for (int n = 0, i = 0; str[i] != '\0'; i++) {
        if (str[i] == s)
            n++;
        tab[n] = malloc(my_strlen(str) + 1);
    }
    for (int n = 0, i = 0, j = 0; str[i] != '\0'; i++, j++) {
        if (str[i] == s) {
            tab[n][i] = '\0';
            n++;
            i++;
            j = 0;
        }
        tab[n][j] = str[i];
        if (str[j + 1] == '\0')
            tab[n][j + 1] = '\0';
    }
    tab[divide(str, s)] = NULL;
    return tab;
}
