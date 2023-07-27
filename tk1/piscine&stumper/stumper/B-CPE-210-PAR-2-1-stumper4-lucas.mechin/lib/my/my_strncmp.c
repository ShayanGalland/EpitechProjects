/*
** EPITECH PROJECT, 2022
** my_strncmp
** File description:
** my_strncmp
*/

#include "my.h"

int my_strncmp(char const *str1, char const *str2, int n)
{
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0' && i < n; i++) {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
    }
    return (0);
}
