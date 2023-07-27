/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** project main
*/

#include "../include/include.h"
#include <stdio.h>
#include <stdlib.h>

void compartment(char *comp, char **sbml)
{
    char *new_comp = my_strcat_aloc("compartment=\"", comp);
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
    printf("List of species in compartment %s\n", comp);
    prt_in_alphabetic(array, comp);
}

char **reaction_separate2(char **array, char **sbml, int l, int n)
{
    for (int i = n, k = 0; i != l + n; i++) {
        if (my_strstr(sbml[i], "species=\"") != NULL) {
            array[k] = find_product2(sbml[i]);
            k++;
        }
    }
    return array;
}

void reaction_separate(char **sbml, char **array, int n, char *comp)
{
    int l = 0;

    for (int i = n, k = 0; sbml[i] != NULL; i++) {
        if (my_strstr(sbml[i], "species=\"") != NULL) {
            array[k] = find_product2(sbml[i]);
            k++;
        } else {
            n += k;
            l = k;
            break;
        }
    }
    l *= 2;
    printf("List of reactants of reaction %s\n", comp);
    prt_in_alphabetic(array, comp);
    reaction_separate2(array, sbml, l, n);
    printf("List of products of reaction %s\n", comp);
    prt_in_alphabetic(array, comp);
}

void reaction(char *comp, char **sbml)
{
    char *new_comp = my_strcat_aloc("id=\"", comp);
    char **array = NULL;
    int n = 0;
    int count = 0;

    for (int i = 0; sbml[i] != NULL; i++) {
        if (my_strstr(sbml[i], new_comp) != NULL) {
            n = i;
            break;
        }
    }
    n += 2;
    for (int i = n; sbml[i] != NULL; i++) {
        if (my_strstr(sbml[i], "species=\"") != NULL)
            count++;
        else
            break;
    }
    array = malloc(sizeof(char*) * count);
    reaction_separate(sbml, array, n, comp);
}
