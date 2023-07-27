/*
** EPITECH PROJECT, 2022
** y
** File description:
** y
*/

#include <stdlib.h>

unsigned int generate_random_number(int min, int max)
{
    int result  = rand() % ((max + 1) - min) + min;

    return result;
}
