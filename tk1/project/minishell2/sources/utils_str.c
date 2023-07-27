/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "../include/functions.h"

char *my_strcat_aloc(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    int new_len = len1+len2+1;
    char *str = malloc(sizeof(char)*new_len);
    int offset_str = 0;

    for (int i = 0; i < new_len-1; i++) {
        if (i < len1) {
            str[i] = str1[i];
            offset_str++;
        } else
            str[i] = str2[i-offset_str];
    }
    str[new_len-1] = '\0';
    return str;
}


void clean_trailingspace(char *str)
{
    for (int i = my_strlen(str); i >= 0; i--) {
        if (str[i] != ' ')
            break;
        if (str[i] == ' ')
            str[i] = '\0';
    }
}

char *no_space(char *new_str, char *old_str)
{
    int one_space = 0;
    int n = 0;

    for (int i = 0; i != my_strlen(old_str); i++) {
        while (old_str[i] == ' ' && i != my_strlen(old_str)-1 && n != 0) {
            one_space++;
            i++;
        }
        if (one_space >= 1 && i != my_strlen(old_str)) {
            new_str[n] = ' ';
            n++;
        }
        if (old_str[i] != ' ') {
            new_str[n] = old_str[i];
            n++;
            one_space = 0;
        }
    }
    free(old_str);
    clean_trailingspace(new_str);
    return new_str;
}


char *delete_space(char *str)
{
    int count = 0;
    int one_space = 0;
    char *new_str = NULL;

    for (int i = 0; i != my_strlen(str); i++) {
        if (str[i] == '\t')
            str[i] = ' ';
    }

    for (int i = 0; i != my_strlen(str); i++) {
        if (str[i] == ' ')
            one_space++;
        if (one_space == 1)
            count++;
        if (str[i] != ' ') {
            count++;
            one_space = 0;
        }
    }
    new_str = malloc(sizeof(char)*(count+1));
    my_memset(new_str, 0, sizeof(char)*(count+1));
    return no_space(new_str, str);
}

char *line_zero(char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '\n')
            line[i] = '\0';
    }
    return line;
}
