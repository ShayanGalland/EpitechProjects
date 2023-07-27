/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** mine is bigger lul
*/

int my_strlen(char const *str)
{
    int len = 0;

    for (int n = 0; str[n] != '\0'; n++)
        len++;
    return (len);
}
