/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** getting higher
*/

char *my_strupcase(char *str)
{
    for (int n = 0; str[n] != '\0'; n++)
        if (str[n] >= 'a' && str[n] <= 'z')
            str[n] = str[n] - 32;
    return (str);
}
