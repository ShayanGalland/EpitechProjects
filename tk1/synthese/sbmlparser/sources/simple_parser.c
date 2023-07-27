/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** project main
*/

#include "../include/include.h"
#include <stdio.h>

int *find_lines(char **buffer, int *lines)
{
    int count = 0;
    int valide = 0;

    for (int j = 1; buffer[j] != NULL; j++) {
        for (int i = 0; i < my_strlen(buffer[j]); i++)
            valide += find_quote(buffer[j][i]);
        if (valide != 0) {
            lines[count] = j;
            count++;
        }
        valide = 0;
    }
    return lines;
}

int find_no_nul(char **array, int shift)
{
    int i = shift;

    while (array[i] == 0)
        i++;
    return i;
}

int find_no_nul2(char **array)
{
    int i = 0;

    while (array[i] == 0)
        i++;
    return i;
}

int real_len(int *lines, int len)
{
    int new_len = len;

    for (int w = 0; w != len; w++) {
        if (lines[w] == 0)
            new_len--;
    }
    return new_len;
}

void fil_array_sbml_parser(int *lines, char **buffer, int len)
{
    int i = 0;
    int count = 0;
    int new_len = 0;

    new_len = real_len(lines, len);
    while (i != len) {
        buffer[lines[i]] = rm_start_spaces(buffer[lines[i]]);
        i++;
    }
    while (count != new_len) {
        i = alphabetic(lines, buffer, len);
        separate_str(buffer[lines[i]]);
        lines[i] = 0;
        printf("\n");
        count++;
    }
}
