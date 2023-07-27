/*
** EPITECH PROJECT, 2021
** emacs emacs
** File description:
** emacs
*/
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char *duplicate_string(char const *src)
{
    int len_src = my_strlen(src);
    char *dest = malloc(sizeof(char)*(len_src+1));
    for (int i = 0;i != len_src;i++)
        dest[i] = src[i];
    return dest;
}
int main ()
{
    printf("%s",duplicate_string("je mange du pain"));
}
