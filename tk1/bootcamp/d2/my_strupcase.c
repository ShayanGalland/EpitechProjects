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

char *my_strupcase(char *str)
{
    for (int i = 0;str[i] != '\0';i++) {
        if (str[i] >= 97 && str[i] <= 122)
            i++;
        str[i]=str[i]-32;
    }
    return str;
}
