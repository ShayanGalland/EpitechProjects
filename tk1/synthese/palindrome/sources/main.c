/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** project main
*/

#include "../include/include.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int help_display(void)
{
    printf("USAGE\n");
    printf("    ./palindrome -n number -p palindrome ");
    printf("[-b base] [-imin i] [-imax i]\n");
    printf("\n");
    printf("DESCRIPTION\n");
    printf("    -n n     integer to be transformed (>=0)\n");
    printf("    -p pal   palindromic number to be obtained ");
    printf("(incompatible with the -n\n             option) (>=0)\n");
    printf("             if defined, all fitting values of n will be output");
    printf("\n    -b base  base in which the procedure will be executed ");
    printf("(1<b<=10) [def: 10]\n");
    printf("    -imin i  minimum number of iterations, included ");
    printf("(>=0) [def: 0]\n");
    printf("    -imax i  maximum number of iterations, included ");
    printf("(>=0) [def: 100]\n");
    return 0;
}

void check_limits(palindrome_t *palindrome)
{
    if (palindrome->base > 10 || palindrome->base <= 1) {
        write(2, "invalid argument\n", 17);
        exit(84);
    }
    if (palindrome->imax < 0 || palindrome->imin < 0) {
        write(2, "invalid argument\n", 17);
        exit(84);
    }
    if (palindrome->imin > palindrome->imax) {
        write(2, "invalid argument\n", 17);
        exit(84);
    }
}

int flag_parse(char **argv, palindrome_t *palindrome)
{
    check_limits(palindrome);
    if (my_strcmp(argv[1], "-n") == 0)
        return in_palindrome(argv[2], 1, palindrome);
    if (my_strcmp(argv[1], "-p") == 0)
        return all_palindrome(argv[2], palindrome);
    return 84;
}

int commands_parse(int argc, char **argv, palindrome_t *palindrome)
{
    if (my_strcmp(argv[1], "-h") == 0)
        return help_display();
    check_number(argv[2]);
    for (int i = 3; argc > i; i += 2) {
        check_number(argv[i + 1]);
        if (my_strcmp(argv[i], "-b") == 0)
            palindrome->base = atoi(argv[i + 1]);
        if (my_strcmp(argv[i], "-imax") == 0)
            palindrome->imax = atoi(argv[i + 1]);
        if (my_strcmp(argv[i], "-imin") == 0)
            palindrome->imin = atoi(argv[i + 1]);
        if (my_strcmp(argv[i], "-p") == 0 || my_strcmp(argv[i], "-n") == 0) {
            write(2, "invalid argument\n", 17);
            return 84;
        }
    }
    return flag_parse(argv, palindrome);
}

int main(int argc, char **argv)
{
    palindrome_t palindrome;

    palindrome.imax = 100;
    palindrome.imin = 0;
    palindrome.base = 10;
    palindrome.iter = 0;
    palindrome.no_result = 0;
    if (argc < 2 || argc == 4 || argc == 6 ||
    argc == 8 || argc == 2 || argc > 9) {
        write(2, "invalid argument\n", 17);
        return 84;
    }
    return commands_parse(argc, argv, &palindrome);
}
