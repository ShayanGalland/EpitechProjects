/*
** EPITECH PROJECT, 2021
** my_strlen
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

int my_strlen(char const *s)
{
    int i = 0;
    while(s[i] != '\0')
        i++;
    return(i);
}
