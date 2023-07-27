/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "functions.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

void my_strcpy(char *dst, const char *src)
{
    for (int i = 0; src[i] != '\0';i++)
        dst[i] = src[i];
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

int is_same_str(char *token, char *str, int i, int token_len)
{
    for (int j = 0; j < token_len;j++) {
        if (str[i+j] != token[j]) {
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

    for (int i = 0; str[i+token_len] != '\0';i++){
        found = 1;
        found = is_same_str(token, str, i, token_len);
        if (found == 1)
            return &str[i];
    }
    return NULL;
}

char *my_strcat(char *dst, const char *src)
{
    int end_dst = 0;
    int i = 0;

    for(; dst[end_dst] != '\0'; end_dst++)
        ;
    for(;src[i] != '\0';i++)
        dst[end_dst+i] = src[i];
    dst[end_dst+i+1] = '\0';
    return &dst[i];
}


