/*
** EPITECH PROJECT, 2023
** the .c file
** File description:
** project c file
*/

#include "string.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char find_at_pos(const string_t *this , size_t pos)
{
    if (pos < 0 || pos > my_strlen(this->str))
        return -1;
    else
        return this->str[pos];
}
