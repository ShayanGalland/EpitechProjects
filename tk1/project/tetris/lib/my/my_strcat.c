/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** cats are the bests
*/

char *my_strcat(char *dest, char const *src)
{
    int n;
    int i;

    for (n = 0; dest[n] != '\0'; n++);
    for (i = 0; src[i] != '\0'; i++)
        dest[n + i] = src[i];
    dest[n + i] = '\0';
    return (dest);
}
