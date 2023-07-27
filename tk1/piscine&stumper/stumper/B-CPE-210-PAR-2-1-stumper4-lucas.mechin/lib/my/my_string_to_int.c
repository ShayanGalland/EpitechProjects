/*
** EPITECH PROJECT, 2021
** my_string_to_int
** File description:
** my_string_to_int
*/

#include "my.h"

int my_strlen(char const *);

int my_string_to_int(char *str)
{
    int p = 0;
    int i = my_strlen(str);
    int m = 1;

    while (i >= 0) {
        if ('0' <= str[i] && str[i] <= '9') {
            p += (str[i] - '0') * m;
            m *= 10;
        }
        i--;
    }
    if (str[0] == '-')
        p *= -1;
    return (p);
}
