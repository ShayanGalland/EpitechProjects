/*
** EPITECH PROJECT, 2021
** y
** File description:
** y
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int my_strncmp(char const *s1 , char const *s2 , int n)
{
    if (s1[n] < s2[n])
        return -1;
    if (s1[n] > s2[n])
        return 1;
    if (s1[n] == s2[n])
        return 0;
    return 0;
}
