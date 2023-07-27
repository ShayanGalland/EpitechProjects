/*
** EPITECH PROJECT, 2022
** my_strduparray
** File description:
** my_strduparray
*/

#include "stdlib.h"
#include "unistd.h"

int check_array(char **src)
{
    int a = 0;

    while (src[a] != NULL)
        a++;
    return a;
}

char **my_strdup_array(char **src)
{
    char **copy;
    int i = 0;

    copy = malloc(sizeof(char*) * (check_array(src) + 1));
    while (src[i] != NULL) {
        copy[i] = src[i];
        i += 1;
    }
    copy[i] = NULL;
    return (copy);
}
