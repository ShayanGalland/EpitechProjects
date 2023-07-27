/*
** EPITECH PROJECT, 2021
** min_three
** File description:
** y
*/
#include "functions.h"

int min_three(int a, int b, int c)
{
    int m = a;
    if (m > b)
        m = b;
    if (m > c)
        m = c;
    return m;
}
