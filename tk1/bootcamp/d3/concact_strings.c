/*
** EPITECH PROJECT, 2021
** emz
** File description:
** kjdh
*/
int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char *concat_strings( char * dest , char const * src )
{
    int i = 0;
    int j = my_strlen(dest);

    while (src[i] != '\0') {
        dest[j] = src[i];
        i = i + 1;
        j = j + 1;
    }
    return (dest);
}
