/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}