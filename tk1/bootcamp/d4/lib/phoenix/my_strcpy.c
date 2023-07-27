/*
** EPITECH PROJECT, 2021
** y
** File description:
** y
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char *my_strcpy(char *dest , char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return dest;
}
