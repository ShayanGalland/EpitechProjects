/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "functions.h"

int my_getnbr(char const *str)
{
    int dest = 0;
    int i = 0;
    int j = 0;
    while (str[i] != '\0') {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] != '+' && str[i] != '-'))
            break;
        if (str[i] == '-')
            j++;
        i++;
    }
    while (str[i] != '\0') {
        while (str[i] >= '0' && str[i] <= '9') {
            dest = dest * 10 + (str[i] - '0');
            i++;
        }
        dest = (j % 2 == 1) ? dest * (-1): dest;
        return (dest);
    }
    return 0;
}

