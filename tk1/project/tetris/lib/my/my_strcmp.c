/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** meh, y'all are the same
*/

int my_strcmp(char const *s1, char const *s2)
{
    for (int n = 0; s1[n] == s2[n]; n++)
        if (s1[n + 1] == '\0' && s2[n + 1] == '\0')
            return 0;
    return 1;
}
