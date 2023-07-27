/*
** EPITECH PROJECT, 2021
** y
** File description:
** y
*/
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c)
{
    write(1, &c ,1);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *concat_parameters(int lenght, char **all_str)
{
    int size_str = 0;
    int size_all = 0;
    int p = 0;
    char *concat = NULL;

    for (int l = 0;l != lenght;l++) {
        for (int n = 0;all_str[l][n] != '\0';n++)
            size_all++;
        size_str++;
    }
    concat = malloc(sizeof(char)*((size_str*2)+size_all));

    for (int i = 0; i != lenght;i++) {
        for (int e = 0;all_str[i][e] != '\0';e++) {
            concat[p] = all_str[i][e];
            p++;
        }
        concat[p] = '\n';
        p++;
    }
    return concat;
}
