/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "include.h"

char *my_restrcat(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    int newLen = len1+len2+1;
    char *str = malloc(sizeof(char)*newLen);
    int offsetStr1 = 0;

    for (int i = 0; i < newLen-1; i++) {
        if (i < len1) {
            str[i] = str1[i];
            offsetStr1++;
        } else
            str[i] = str2[i-offsetStr1];
    }
    str[newLen-1] = '\0';
    return str;
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

void my_itoa(char *buffer, int number)
{
    int i;
    int sign;

    sign = number;
    if (sign < 0)
        number = -number;
    i = 0;
    do {
        buffer[i++] = number % 10 + '0';
    } while ((number /= 10) > 0);
    if (sign < 0)
        buffer[i++] = '-';
    buffer[i] = '\0';
    reverse(buffer);
}