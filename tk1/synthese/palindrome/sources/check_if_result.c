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

int p_result_palindrome(int count, char *buffer, int mode, palindrome_t *pal)
{
    char *end;

    if (pal->iter == pal->imax + 1)
        return -1;
    if (mode == 2 && is_palindrome(buffer) && strtol
    (pal->pnum, &end, 10)
    == strtol(buffer, &end, pal->base) && pal->imin - 1 >= pal->iter)
        return -1;
    if (mode == 2 && is_palindrome(buffer) && strtol
    (pal->pnum, &end, 10)
    == strtol(buffer, &end, pal->base)) {
        pal->no_result++;
        return 1;
    }
    if (mode == 2 && strtol(pal->pnum, &end, 10) <
    strtol(buffer, &end, pal->base))
        return -1;
    return 0;
}

int result_palindrome(long count, char *buffer, int mode, palindrome_t *pal)
{
    char *end;

    if (pal->iter == pal->imax + 1 && mode != 2) {
        printf("no solution\n");
        return -1;
    }
    if (is_palindrome(buffer) && mode == 0 && pal->imin <= pal->iter) {
        printf("%ld leads to %ld in 0 iteration(s) in base %d\n", strtol(
        buffer, &end, pal->base), strtol(buffer, &end, pal->base), pal->base);
        return -1;
    }
    if ((count == LONG_MAX && mode != 2) || (strtol(buffer, &end, pal->base)
    == LONG_MAX && mode != 2)) {
        printf("no solution\n");
        return -1;
    }
    if (is_palindrome(buffer) && mode == 1 && pal->iter >= pal->imin)
        return 1;
    return p_result_palindrome(count, buffer, mode, pal);
}