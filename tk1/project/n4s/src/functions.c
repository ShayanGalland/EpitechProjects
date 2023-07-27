/*
** EPITECH PROJECT, 2021
** string
** File description:
** str
*/

#include "my.h"

int get_nb_line(char const *str, char delim)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == delim)
            ++nb;
    return (nb);
}

int my_strlen(char const *str, char delim)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != delim)
        ++i;
    return (i);
}

char *get_word(char const *str, char delim)
{
    char *dest = malloc(sizeof(char) * (my_strlen(str, delim) +  1));
    int i = 0;

    while (str[i] != delim && str[i] != 0) {
        dest[i] = str[i];
        ++i;
    }
    dest[i + 1] = 0;
    return (dest);
}

char **my_str_to_word_array(char const *str, char n)
{
    char **tab = malloc(sizeof(char *) * (get_nb_line(str, n) + 2));
    for (int i = 0; str[0] != 0; ++i) {
        tab[i] = get_word(str, n);
        tab[i + 1] = NULL;
        while (str[0] != n && str[0] != 0)
            ++str;
        if (str[0] == n)
            ++str;
    }
    return (tab);
}

void free_arr(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}
