/*
** EPITECH PROJECT, 2022
** str_to_world_array
** File description:
** str_to_world_array
*/

#include "stdlib.h"
#include "unistd.h"

int my_space(char character)
{
    int y = 1;
    int i = 0;

    if (character >= '!' && character <= 'z' && character != ':'
    && character != '=' && character != '\t' && character != '\v')
        return (y);
    return (i);
}

int string(char *str, int space)
{
    for (int s = 0; str[s] != '\0'; s++) {
        if (my_space(str[s]) != 1)
            return (space);
        s++;
    }
    return (space);
}

int count_space(char *str)
{
    int ac = 0;

    for (int p = 0; str[p] != '\0'; p++) {
        if (my_space(str[p]) == 1 && my_space(str[p + 1]) == 0) {
            ac ++;
        }
    }
    return (ac);
}

char **my_str_to_word_array(char *str)
{
    char **change;
    int a;
    int p = 0;
    int space = 0;
    int my_count_space = count_space(str);

    change = malloc(sizeof(char *) * (my_count_space + 1));
    for (a = 0; a < my_count_space && str[space] != '\0'; a++, space++) {
        while (str[space] != '\0' && my_space(str[space]) == 0)
            space++;
        p = 0;
        change[a] = malloc(sizeof(char) * (string(str, space) + 32000));
        for (; str[space] != '\0' && my_space(str[space]) == 1; space++) {
            change[a][p] = str[space];
            p++;
        }
        change[a][p] = '\0';
    }
    change[a] = NULL;
    return (change);
}
