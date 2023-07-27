/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** project main
*/

#include "../include/include.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int init_palindrome(char *buffer, int flag, char *num, palindrome_t *pal)
{
    memset(buffer, '\0', 256);
    if (flag != 2)
        my_itoa(buffer, atoi(num), pal->base);
    else
        fil_buffer(num, buffer);
}

int in_palindrome(char *num, int flag, palindrome_t *palindrome)
{
    char buffer[256];
    long count = 0;
    char *end;

    init_palindrome(buffer, flag, num, palindrome);
    check_if_already_palindrome(flag, count, buffer, palindrome);
    while (1) {
        count = strtol(buffer, &end, palindrome->base) +
        strtol(my_revstr(buffer), &end, palindrome->base);
        my_itoa(buffer, count, palindrome->base);
        palindrome->iter++;
        if (result_palindrome(count, buffer, flag, palindrome) == -1)
            return 0;
        if (result_palindrome(count, buffer, flag, palindrome))
            break;
    }
    printf("%ld leads to %ld in %d iteration(s) in base %d\n",
    strtol(num, &end, flag == 2 ? palindrome->base : 10), strtol(
    buffer, &end, palindrome->base), palindrome->iter, palindrome->base);
    return 0;
}

int no_soluce_p(char *num, palindrome_t *palindrome)
{
    if (palindrome->no_result == 0 && palindrome->imin != 0) {
        printf("no solution\n");
        return 0;
    }
    if (palindrome->imin == 0) {
        printf("%s leads to %s in 0 iteration(s) in base %d\n"
        , num, num, palindrome->base);
        return 0;
    }
    return 0;
}

int all_palindrome(char *num, palindrome_t *palindrome)
{
    char buffer[256];

    my_itoa(buffer, atoi(num), palindrome->base);
    palindrome->pnum = num;
    if (!is_palindrome(buffer)) {
        write(2, "invalid argument\n", 17);
        return 84;
    }
    for (int i = 1; i < atoi(num); i++) {
        memset(buffer, '\0', 256);
        my_itoa(buffer, i, palindrome->base);
        in_palindrome(buffer, 2, palindrome);
        palindrome->iter = 0;
    }
    return no_soluce_p(num, palindrome);
}
