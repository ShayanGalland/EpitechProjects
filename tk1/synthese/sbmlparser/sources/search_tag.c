/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** project main
*/

#include "../include/include.h"
#include <stdio.h>
#include <stdlib.h>

int search_tag(char *comp, char **sbml, char *new_comp)
{
    int tag = 0;

    tag = find_tag(new_comp, sbml);
    if (tag == 1)
        compartment(comp, sbml);
    if (tag == 2)
        species(comp, sbml);
    if (tag == 3)
        reaction(comp, sbml);
    if (tag == 4)
        other(comp, sbml);
    return 84;
}

int select_tag(char *tag)
{
    if (my_strcmp(tag, "compartment") == 0)
        return 1;
    if (my_strcmp(tag, "species ") == 0)
        return 2;
    if (my_strcmp(tag, "reaction") == 0)
        return 3;
    return 4;
}

int find_tag(char *comp, char **sbml)
{
    int n = 0;
    char *str = NULL;
    int w = 1;

    for (int i = 0; sbml[i] != NULL; i++) {
        if (my_strstr(sbml[i], comp) != NULL) {
            n = i;
            break;
        }
        if (sbml[i + 1] == NULL)
            return 4;
    }
    while (sbml[n][w] != ' ')
        w++;
    str = malloc(sizeof(char) * (w + 1));
    w = 1;
    while (sbml[n][w] != ' ') {
        str[w - 1] = sbml[n][w];
        w++;
    }
    return select_tag(str);
}

char *fil_product(char *str, int i)
{
    int len = 0;
    char *find = NULL;
    int n = 0;

    while (str[i] != 34) {
        len++;
        i++;
    }
    find = malloc(sizeof(char) * (len + 1));
    i -= len;
    for (int w = i; str[w] != 34; w++) {
        find[n] = str[w];
        n++;
    }
    return find;
}

void prt_in_alphabetic(char **array, char *comp)
{
    int n = 0;
    int count = 0;

    while (count != count_array(array)) {
        n = alphabetic_array(array, 0);
        printf("--->%s", array[n]);
        if (count != count_array(array) - 1)
            printf("\n");
        array[n][0] = 127;
        n++;
        count++;
    }
    printf("\n");
}
