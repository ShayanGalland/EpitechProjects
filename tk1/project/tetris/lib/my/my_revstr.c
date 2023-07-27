/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** uno reverse card
*/

int my_strlen(char *str);

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
