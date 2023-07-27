/*
** EPITECH PROJECT, 2021
** synthese
** File description:
** synthese project
*/

#include <stdlib.h>
#include <stdio.h>

static int is_alphanum(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

static int check_separators(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alphanum(str[i]) == 0 && is_alphanum(str[i + 1]) == 1)
            nb++;
    }
    if (is_alphanum(str[0]) == 0)
        nb--;
    nb++;
    return (nb);
}

static int start_i(char const *str)
{
    int i = 0;

    while (is_alphanum(str[i]) == 0)
        i++;
    return i;
}

static char **malloc_part(char **array, char const *str)
{
    int count = 0;
    int j = 0;

    for (int i = start_i(str); str[i] != '\0'; i++) {
        if (is_alphanum(str[i]) == 1)
            count++;
        if (is_alphanum(str[i]) == 0 && is_alphanum(str[i + 1]) == 1) {
            array[j] = malloc(sizeof(char) * (count + 1));
            j++;
            count = 0;
        }
        if (str[i + 1] == '\0')
            array[j] = malloc(sizeof(char) * (count + 1));
    }
    return array;
}

char **my_str_to_word_array_synthesis(char const *str)
{
    char **array = malloc(sizeof(char *) * (check_separators(str) + 1));
    int j = 0;
    int n = 0;

    array = malloc_part(array, str);
    for (int i = start_i(str); str[i] != '\0'; i++) {
        if (is_alphanum(str[i]) == 0 && is_alphanum(str[i + 1]) == 1) {
            array[j][n] = '\0';
            j++;
            n = 0;
        }
        if (is_alphanum(str[i]) == 1) {
            array[j][n] = str[i];
            n++;
        }
        if (str[i + 1] == '\0')
            array[j][n] = '\0';
    }
    array[j + 1] = 0;
    return array;
}
