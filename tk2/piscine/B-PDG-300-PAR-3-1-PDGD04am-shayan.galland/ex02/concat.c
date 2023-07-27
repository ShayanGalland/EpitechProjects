/*
** EPITECH PROJECT, 2023
** project
** File description:
** in c
*/

#include "functions.h"
#include "concat.h"

void concat_strings(const char *str1 , const char *str2 , char **res)
{
    *res = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
    memset(*res, 0, sizeof(char));
    strcat(*res, str1);
    strcat(*res, str2);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

void concat_struct(concat_t *str)
{
    str->res = malloc(sizeof(char) * (strlen(str->str1) +
    strlen(str->str2) + 1));
    memset(str->res, 0, sizeof(char));
    strcat(str->res, str->str1);
    strcat(str->res, str->str2);
}
