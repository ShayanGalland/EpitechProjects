/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** reverse a string
*/

int my_strlen(char const *str);
char * my_revstr ( char * str)
{
    char time = 0;
    int i = 0;
    int j = my_strlen(str);

    while (i < j - 1) {
        time = str[i];
        str[i] = str[j - 1];
        str[j - 1] = time;
        i = i + 1;
        j = j - 1;
    }
    return (str);
}
