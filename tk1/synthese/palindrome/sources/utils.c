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

int is_palindrome(char *num)
{
    int len = my_strlen(num);

    if (num == NULL)
        return 0;
    for (int i = 0; num[i] ; i++) {
        if (num[i] != num[len - i - 1])
            return 0;
    }
    return 1;
}

void fil_buffer(char *num, char *buffer)
{
    for (int i = 0; num[i] != '\0'; i++)
        buffer[i] = num[i];
    buffer[my_strlen(num)] = '\0';
}

void check_if_already_palindrome(int flag, int count, char *buffer,
palindrome_t *palindrome)
{
    if (flag != 2) {
        if (result_palindrome(count, buffer, 0, palindrome) == -1)
            exit(0);
    }
}

void check_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 48 || str[i] > 57) {
            write(2, "invalid argument\n", 17);
            exit(84);
        }
    }
}