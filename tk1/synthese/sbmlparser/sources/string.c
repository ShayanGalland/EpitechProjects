/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** project main
*/

#include "../include/include.h"
#include <stdlib.h>

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

char *my_strcat_aloc(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    int new_len = len1 + len2 + 1;
    char *str = malloc(sizeof(char) * new_len);
    int offset_str = 0;

    for (int i = 0; i < new_len - 1; i++) {
        if (i < len1) {
            str[i] = str1[i];
            offset_str++;
        } else
            str[i] = str2[i - offset_str];
    }
    str[new_len - 1] = '\0';
    return str;
}

int is_same_str(const char *token, const char *str, int i, int token_len)
{
    for (int j = 0; j < token_len;j++) {
        if (str[i + j] != token[j]) {
            return 0;
            break;
        }
    }
    return 1;
}

const char *my_strstr(const char *str, const char *token)
{
    int found = 1;
    int token_len = my_strlen(token);

    for (int i = 0; str[i] != '\0'; i++){
        found = 1;
        found = is_same_str(token, str, i, token_len);
        if (found == 1)
            return &str[i];
    }
    return NULL;
}