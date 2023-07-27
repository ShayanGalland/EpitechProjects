/*
** EPITECH PROJECT, 2021
** MY_EVIL_STR
** File description:
** ok
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = 0;
    int a = my_strlen(str) - 1;
    int b;

    while (i < a) {
        b = str[i];
        str[i] = str[a];
        str[a] = b;
        i = i + 1;
        a = a - 1;
    }
    return (str);
}
