/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** project main
*/

#include "../include/include.h"
#include <stdlib.h>

int my_strlen(char const *str)
{
    int len = 0;

    if(str == NULL)
        return 0;
    for (int n = 0; str[n] != '\0'; n++)
        len++;
    return (len);
}

int my_strcmp(const char *str1, const char *str2)
{
    int str1_size = my_strlen(str1);
    int str2_size = my_strlen(str2);
    int i = 0;

    if (str1_size != str2_size)
        return -1;
    while (i < str1_size) {
        if (str1[i] != str2[i])
            return -1;
        i++;
    }
    return 0;
}

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char dest[len + 1];

    for (int n = 0; str[n] != '\0'; n++)
        dest[n] = str[len - n - 1];
    for (int n = 0; str[n] != '\0'; n++)
        str[n] = dest[n];
    return (str);
}

static void reverse(char buffer[])
{
    int j = my_strlen(buffer) - 1;
    char c;

    for (int i = 0; i < j; i++, j--) {
        c = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = c;
    }
}

void my_itoa(char *buffer, int number, int base)
{
    int i;
    int sign;

    sign = number;
    if (sign < 0)
        number = -number;
    i = 0;
    do {
        buffer[i++] = number % base + '0';
    } while ((number /= base) > 0);
    if (sign < 0)
        buffer[i++] = '-';
    buffer[i] = '\0';
    reverse(buffer);
}
