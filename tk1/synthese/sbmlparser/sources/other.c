/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** project main
*/

#include "../include/include.h"
#include <stdlib.h>
#include <stdio.h>

char *find_product2(char *str)
{
    int i = 0;
    int n = 0;
    char *find = malloc(sizeof(char) * 10);

    while (str[i] != '\0') {
        while (n != 9) {
            find[n] = str[i + n];
            n++;
        }
        if (my_strcmp(find, "species=\"") == 0)
            break;
        i++;
        n = 0;
    }
    i += 9;
    free(find);
    return fil_product(str, i);
}

void other(char *comp, char **sbml)
{
    char *new_comp = my_strcat_aloc("<spe", "cies ");
    char **array = NULL;
    int n = 0;

    for (int i = 0; sbml[i] != NULL; i++) {
        if (my_strstr(sbml[i], new_comp) != NULL)
            n++;
    }
    array = malloc(sizeof(char*) * n);
    for (int i = 0, k = 0; sbml[i] != NULL; i++) {
        if (my_strstr(sbml[i], new_comp) != NULL) {
            array[k] = find_product(sbml[i]);
            k++;
        }
    }
    printf("List of species\n");
    prt_in_alphabetic(array, comp);
    comp = comp;
}

void species(char *comp, char **sbml)
{
    return;
}