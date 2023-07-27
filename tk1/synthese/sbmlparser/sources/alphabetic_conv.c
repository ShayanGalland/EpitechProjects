/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** project main
*/

#include "../include/include.h"
#include <stdlib.h>
#include <stdio.h>

void separate_str(char *str)
{
    char **array = str_in_alpha_array(str);
    int n = 0;
    int count = 0;

    printf("%s\n", array[0]);
    while (count != count_array(array) - 1) {
        n = alphabetic_array(array, 1);
        printf("--->%s", array[n]);
        if (count != count_array(array) - 2)
            printf("\n");
        array[n][0] = 127;
        n++;
        count++;
    }
}

int find_no_zero(int *lines)
{
    int i = 0;

    while (lines[i] == 0)
        i++;
    return i;
}

int alphabetic(int *lines, char **buffer, int len)
{
    int i = 1;
    int count = 1;
    int bigger = find_no_zero(lines);

    while (i != len) {
        while (buffer[lines[bigger]][count] == buffer[lines[i]][count]
        && lines[i] != 0 && buffer[lines[bigger]][count] != ' ')
            count++;
        if (buffer[lines[i]][count] <= buffer[lines[bigger]][count]
        && lines[i] != 0)
            bigger = i;
        i++;
        count = 1;
    }
    return bigger;
}

char **str_in_alpha_array(char *str)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    char **array = NULL;
    int i = 1;
    int n = 0;

    while (str[i] != ' ') {
        new_str[n] = str[i];
        i++;
        n++;
    }
    while (str[i] != '\0') {
        new_str[n] = str[i];
        if (str[i] == '=')
            i = skip_quote(str, i);
        i++;
        n++;
    }
    array = my_str_to_word_array_synthesis(new_str);
    return array;
}

int alphabetic_array(char **array, int shift)
{
    int bigger = find_no_nul(array, shift);
    int i = 1;
    int count = 0;

    while (array[i] != 0) {
        while (array[bigger][count] == array[i][count] &&
        array[bigger][count] != '\0' && array[i][0] != 127)
            count++;
        if (array[i][count] <= array[bigger][count] && array[i][0] != 127)
            bigger = i;
        i++;
        count = 0;
    }
    return bigger;
}
