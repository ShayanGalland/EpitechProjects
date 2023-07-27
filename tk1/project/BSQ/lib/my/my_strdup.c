/*
** EPITECH PROJECT, 2021
** emas
** File description:
** emacs
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src)));
    if (dest == NULL)
        return (NULL);
    my_strcpy(dest, src);
    dest[my_strlen(src)] = '\0';
    return (dest);
}
