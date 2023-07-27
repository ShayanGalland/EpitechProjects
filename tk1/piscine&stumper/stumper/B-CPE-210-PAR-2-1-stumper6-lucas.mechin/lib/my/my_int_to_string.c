/*
** EPITECH PROJECT, 2021
** inttostring
** File description:
** inttostring
*/

#include <stdlib.h>

char *my_revstr(char *str);

char racc_fonct(int value)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 100);

    if (value == 0) {
        str[i] = '0';
        i++;
    }
    return 0;
}

char *my_int_to_string(int value)
{
    int i = 0;
    int n = 0;
    char *str = malloc(sizeof(char) * 100);

    if (value < 0)
        n = 1;
    racc_fonct(value);
    while (value != 0) {
        str[i] = value % 10 + '0';
        value /= 10;
        i++;
    }
    if (n == 1) {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    my_revstr(str);
    return str;
}
