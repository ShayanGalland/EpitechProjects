/*
** EPITECH PROJECT, 2021
** rendu
** File description:
** 
*/

#include <unistd.h>

void my_putchar(char c);
int etoile1(int x);
int etoile2(int x);

void rush(int x)
{
    if(x !=  0)
    {
        etoile1(x);
        etoile2(x);
    }
    else
    {
        my_putchar(' ');
    }
}

        