/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** okk
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *copy;
    int i = 0;

    copy = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[i] != '\0') {
        copy[i] = src[i];
        i += 1;
    }
    return (copy);
}
