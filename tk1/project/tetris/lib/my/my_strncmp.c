/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** there's more of them, all alike
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int nb;

    for (nb = 0; s1[nb] == s2[nb]; nb++) {
        if (s1[nb + 1] == '\0' && s2[nb + 1] == '\0')
            return (0);
        if (nb == n)
            return (0);
    }
    if (s1[nb] == '\0')
        return (-1 * s2[nb]);
    else if (s2[nb] == 0)
        return (s2[nb]);
    else
        return (s1[nb] - s2[nb]);
    return (0);
}
