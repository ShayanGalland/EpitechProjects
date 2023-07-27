/*
** EPITECH PROJECT, 2021
** nbr_cmp
** File description:
** nbr_cmp
*/

#include "my.h"

int extend_strcmp(char const *str1, char const *str2)
{
    int len_1 = my_strlen(str1);
    int len_2 = my_strlen(str2);

    for (int i = 0; i < len_1; i++) {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
    }
}

int my_strcmp(char const *str1, char const *str2)
{
    int len_1 = my_strlen(str1);
    int len_2 = my_strlen(str2);

    if (len_1 < len_2)
        return (-1);
    if (len_1 > len_2)
        return (1);
    if (len_1 == len_2) {
        extend_strcmp(str1, str2);
        return (0);
    }
}
