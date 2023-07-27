/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** y
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void my_putchar(char c)
{
    write(1, &c, 1);
}
int my_putstr (char const *str)
{
    int i = 0;

    while(str[i] != '\0')
    {
        my_putchar(str[i]);
        i = i + 1;
    }
}



