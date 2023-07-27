/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** ok
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        i += 1;
    }
    while (src[j] != '\0') {
        dest[i] = src[j];
        i += 1;
        j += 1;
    }
    dest[i] = '\0';
    return (dest);
}
