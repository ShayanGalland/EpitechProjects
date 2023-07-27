/*
** EPITECH PROJECT, 2021
** y
** File description:
** y
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

long long iterative_factorial(int nb)
{
    long long res = 1;
    for(int i = 1;i <= nb;i++)
        res *= i;
    return res;
}

int main(int argc, char **argv)
{
    printf("%llu", iterative_factorial(atoi(argv[1])));
    return 0;
}