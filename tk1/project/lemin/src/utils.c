/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>

char *clear_comments(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '#' && str[i + 1] != '#' && str[i - 1] != '#')
            str[i]++;
    }
    return str;
}