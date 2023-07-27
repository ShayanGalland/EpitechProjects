/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** my_low_budget_split
*/

#include <stdlib.h>

static int is_alphanum(char c)
{
    if (c >= '!' && c <= 'z')
        return 1;
    return 0;
}

static int check_separators(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (is_alphanum(str[i]) == 0)
            nb++;
    nb++;
    return (nb);
}

static char **malloc1(char *src, char **str)
{
    int i = 0;
    int k = 0;

    for (int j = 0; src[i] != '\0'; i++, k++) {
        if (is_alphanum(src[i]) == 0) {
            str[j] = malloc(sizeof(char) * (k + 1));
            k = 0;
            j++;
        } else if (src[i + 1] == '\0') {
            str[j] = malloc(sizeof(char) * (k + 2));
            k = 0;
            break;
        }
    }
    return (str);
}

char **my_str_to_word_array(char *src)
{
    int nb = check_separators(src);
    char **str = malloc((nb + 1) * sizeof(char *));

    str = malloc1(src, str);
    for (int i = 0, j = 0, k = 0; src[i] != '\0'; i++, k++) {
        if (is_alphanum(src[i]) == 0) {
            str[j][k] = '\0';
            j++;
            k = -1;
            continue;
        } else if (src[i + 1] == '\0') {
            str[j][k] = src[i];
            str[j][k + 1] = '\0';
            break;
        }
        str[j][k] = src[i];
    }
    str[nb] = NULL;
    return (str);
}
