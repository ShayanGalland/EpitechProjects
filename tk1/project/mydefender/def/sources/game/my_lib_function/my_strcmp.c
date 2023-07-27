/*
** EPITECH PROJECT, 2021
** ghj
** File description:
** ghjk
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int res = 1;

    if (my_strlen(s1) != my_strlen(s2))
        return (0);
    for (int i = 0; i < my_strlen(s1); i++) {
        if (s1[i] != s2[i])
            res = 0;
    }
    return (res);
}
