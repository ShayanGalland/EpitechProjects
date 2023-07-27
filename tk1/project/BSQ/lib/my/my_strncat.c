/*
** EPITECH PROJECT, 2021
** fghj
** File description:
** fghjk
*/

int my_strlen(char const *str);

char * my_strncat (char *dest, char const *src, int nb)
{
    int i = 0;
    int j = my_strlen(dest);

    while (i < nb) {
        dest[j] = src[i];
        i = i + 1;
        j = j + 1;
    }
    dest[j] = '\0';
    return (dest);
}
