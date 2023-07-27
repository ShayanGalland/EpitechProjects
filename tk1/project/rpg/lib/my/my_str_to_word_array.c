/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <unistd.h>
#include <stdlib.h>

static int length_to_space(char *str, char sep)
{
    int count = 0;

    while (*str == sep || *str == '\t')
        str++;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep || str[i] == '\t')
            break;
        count++;
    }
    return count;
}

static char *passing(char *str, char sep)
{
    if (*str == sep || *str == '\t') {
        while (*str == sep || *str == '\t') {
            str++;
        }
    }
    while ((*str != sep && *str != '\t') && *str != '\0')
        str++;
    while (*str == sep || *str == '\t')
        str++;
    return str;
}

static int counting_str(char *str, char sep)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep && str[i + 1] != '\0'
            && str[i + 1] != sep) {
            count++;
        }
    }
    count++;
    return count;
}

static char **mallocarray(char **array, int const words, char *str, char sep)
{
    while (*str == sep || *str == '\t')
        str++;
    array = malloc(sizeof(char*) * words + 1);
    for (int i = 0; i < words; i++) {
        array[i] = malloc(sizeof(char) * length_to_space(str, sep) + 1);
        str = passing(str, sep);
    }
    return array;
}

char **my_str_to_word_array(char **array, char *str, char sep)
{
    int const nb_word = counting_str(str, sep);
    int i = 0;

    array = mallocarray(array, nb_word, str, sep);
    for (; i < nb_word; i++) {
        while (*str == sep || *str == '\t')
            str++;
        for (int y = 0; (str[y] != sep && str[y] != '\t')
            && str[y] != '\0'; y++) {
            array[i][y] = str[y];
        }
        str = passing(str, sep);
    }
    array[i] = NULL;
    return array;
}
