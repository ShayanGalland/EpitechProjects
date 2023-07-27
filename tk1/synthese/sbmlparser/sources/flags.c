/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** project main
*/

#include "../include/include.h"
#include <stdio.h>
#include <stdlib.h>

char *find_product(char *str)
{
    int i = 0;
    int n = 0;
    char *find = malloc(sizeof(char) * 7);

    while (str[i] != '\0') {
        while (n != 6) {
            find[n] = str[i + n];
            n++;
        }
        if (my_strcmp(find, "name=\"") == 0)
            break;
        i++;
        n = 0;
    }
    i += 6;
    free(find);
    return fil_product(str, i);
}

int simple_i_flag(char *comp, char *file)
{
    char *buffer = NULL;
    int len_buffer = 0;
    char **sbml = NULL;
    char *new_comp = NULL;

    if (open_read(file, &buffer, &len_buffer) == 84)
        return 84;
    sbml = my_split(sbml, buffer, '\n');
    for (int i = 0; sbml[i] != NULL; i++)
        sbml[i] = rm_start_spaces(sbml[i]);
    new_comp = my_strcat_aloc("id=\"", comp);
    return search_tag(comp, sbml, new_comp);
}

int e_flags(char *comp, char *file)
{
    comp = comp;
    file = file;
    return 0;
}

int j_flags(char *comp, char *file)
{
    comp = comp;
    file = file;
    return 0;
}

int no_comp(char *file)
{
    char *buffer = NULL;
    int len_buffer = 0;
    char **sbml = NULL;

    if (open_read(file, &buffer, &len_buffer) == 84)
        return 84;
    sbml = my_split(sbml, buffer, '\n');
    for (int i = 0; sbml[i] != NULL; i++)
        sbml[i] = rm_start_spaces(sbml[i]);
    other("species", sbml);
    return 0;
}