/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int n = 0;

    while (src[n] != '\0') {
        dest[n] = src[n];
        n = n + 1;
    }
    dest[n] = '\0';
    return (dest);
}
