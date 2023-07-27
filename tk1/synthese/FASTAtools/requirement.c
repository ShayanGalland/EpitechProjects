/*
** EPITECH PROJECT, 2021
** synthese
** File description:
** synthese project
*/

#include <stdio.h>

static int is_alphanum(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= 'a' && c <= 'z')
        return 2;
    return 0;
}

char *my_strcapitalize_synthesis(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (is_alphanum(str[i]) == 0 || is_alphanum(str[i] == 1))
            i++;
        if (is_alphanum(str[i]) == 2 && is_alphanum(str[i - 1]) == 0)
            str[i] -= 32;
        i++;
    }
    return str;
}
