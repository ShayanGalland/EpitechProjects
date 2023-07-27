/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** project main
*/

#include "../include/include.h"
#include <stdlib.h>
#include <stdio.h>

static void help_flag(void)
{
    printf("USAGE\n");
    printf("    ./SBMLparser SBMLfile [-i ID [-e]] [-json]\n");
    printf("\n");
    printf("DESCRIPTION\n");
    printf("    SBMLfile    SBML file\n");
    printf("    -i ID       id of the compartment, reaction or ");
    printf("product to be extracted\n");
    printf("                (ignored if uncorrect)\n");
    printf("    -e          print the equation if a reaction ");
    printf("ID is given as argument\n");
    printf("                (ignored otherwise)\n");
    printf("    -json       transform the file into a JSON file\n");
}

void simple_parser(char **buffer)
{
    int *lines = NULL;
    int count = 0;
    int valide = 0;

    for (int j = 1; buffer[j] != NULL; j++) {
        for (int i = 0; i < my_strlen(buffer[j]); i++)
            valide += find_quote(buffer[j][i]);
        if (valide != 0)
            count++;
        valide = 0;
    }
    lines = malloc(sizeof(int)*count);
    lines = find_lines(buffer, lines);
    lines = different_lines(buffer, lines);
    fil_array_sbml_parser(lines, buffer, count);
}

int sbml_parser(char *file)
{
    char *buffer = NULL;
    int len_buffer = 0;
    char **sbml = NULL;

    if (open_read(file, &buffer, &len_buffer) == 84)
        return 84;
    sbml = my_split(sbml, buffer, '\n');
    simple_parser(sbml);
    return 0;
}

int flags_select(char **argv, int argc)
{
    if (argc == 2)
        return sbml_parser(argv[1]);
    if (argv[2][0] != '-' && argv[2][1] != 'i')
        return 84;
    if (argc == 4)
        return simple_i_flag(argv[3], argv[1]);
    if (argc == 3)
        return no_comp(argv[1]);
    if (argc == 5) {
        if (argv[4][0] == '-' && argv[4][1] == 'e')
            return e_flags(argv[3], argv[1]);
        if (argv[4][0] == '-' && argv[4][1] == 'j' && argv[4][2] == 's')
            return j_flags(argv[3], argv[1]);
    }
    return 84;
}

int main(int argc, char **argv)
{
    int status = 0;

    if (argc == 1)
        return 84;
    if (argc > 5)
        return 84;
    if (my_strlen(argv[1]) == 2 || my_strlen(argv[1]) == 6) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            help_flag();
            return 0;
        }
        if (argv[1][0] == '-' && argv[1][1] == '-') {
            help_flag();
            return 0;
        }
    }
    status = flags_select(argv, argc);
    return status;
}