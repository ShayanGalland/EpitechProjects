/*
** EPITECH PROJECT, 2021
** gh
** File description:
** hgf
*/

char *my_strcpy(char *dest , char const *src)
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i + 1] = '\0';
    return (dest);
}
