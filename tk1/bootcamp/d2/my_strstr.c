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

int t_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

int simple_if(int len_str, int n)
{
    if (n == len_str)
        return 1;
    else
        return 0;
}

char *my_strstr(char *str , char const *to_find)
{
    int len_str = t_strlen(to_find);
    int m = 0;
    char *cmp = NULL;
   
    for (int i = 0;str[i] != '\0';i++) {
        for (int n = 0;to_find[n] == str[i];n++)
            m = simple_if(len_str, n);
    }
    if (m == 0)
        return NULL;
    cmp = malloc(sizeof(char)*(len_str+1));
    for (int i = 0;i != len_str+1;i++)
        cmp[i] = to_find[i];
    return cmp;
}
