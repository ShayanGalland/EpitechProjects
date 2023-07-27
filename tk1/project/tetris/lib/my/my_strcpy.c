/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** i am the cpy
*/

char *my_strcpy(char *dest, char const *src)
{
    for (int n = 0; src[n] != '\0'; n++) {
        dest[n] = src[n];
        if (src[n + 1] == '\0') {
            dest[n + 1] = '\0';
            return (dest);
        }
    }
    return (dest);
}
