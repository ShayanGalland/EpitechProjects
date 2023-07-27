/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** we are the n cpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int x = 0; x <= n; x++) {
        dest[x] = src[x];
        if (src[x] == '\0') {
            dest[x] = '\0';
            return (dest);
        }
    }
    dest[n] = '\0';
    return (dest);
}
