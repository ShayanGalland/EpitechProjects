/*
** EPITECH PROJECT, 2023
** project
** File description:
** in c
*/

int my_strlen(char const *str)
{
    int len = 0;

    for (int n = 0; str[n] != '\0'; n++)
        len++;
    return (len);
}

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char dest[len + 1];

    for (int n = 0; str[n] != '\0'; n++)
        dest[n] = str[len - n - 1];
    for (int n = 0; str[n] != '\0'; n++)
        str[n] = dest[n];
    return (str);
}

char *my_strupcase(char *str)
{
    for (int n = 0; str[n] != '\0'; n++)
        if (str[n] >= 'a' && str[n] <= 'z')
            str[n] = str[n] - 32;
    return (str);
}