/*
** EPITECH PROJECT, 2023
** project
** File description:
** in c
*/

#include "functions.h"

void mul_div_long(int a, int b, int *mul , int *div)
{
    *mul = a * b;
    if (b > 0)
        *div = a / b;
    else
        *div = 42;
}

void mul_div_short(int *a, int *b)
{
    int cal_a = *a;
    int cal_b = *b;

    *a = cal_a * cal_b;
    if (cal_b > 0)
        *b = cal_a / cal_b;
    else
        *b = 42;
}