/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** project main
*/

#include "../include/include.h"
#include <stdio.h>
#include <stdlib.h>

void error_and_help(int argc, char **argv)
{
    if (argc == 2) {
        if (my_strcmp(argv[1], "-h") == 0)
            exit(help());
        else
            exit(84);
    }
    check_number(argv[1]);
    if (argc < 3 || argc > 4)
        exit(84);
}

void check_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 48 || str[i] > 57)
            exit(84);
    }
}

int k_mers(char **argv, fasta_t *fasta)
{
    check_number(argv[2]);
    if (atoi(argv[2]) < 1)
        exit(84);
    if (atoi(argv[1]) != 4)
        exit(84);
    return atoi(argv[2]);
}
