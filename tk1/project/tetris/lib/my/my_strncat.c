/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** a cat is nice, but n cats are n times better
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int n;
    int i;

    for (n = 0; dest[n] != '\0'; n++);
    for (i = 0; i < nb && src[i] != '\0'; i++)
        dest[n + i] = src[i];
    dest[n + i] = '\0';
    return (dest);
}
