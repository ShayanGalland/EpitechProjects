/*
** EPITECH PROJECT, 2021
** my_strlowcase
** File description:
** getting back on the ground level
*/

char *my_strlowcase(char *str)
{
    for (int n = 0; str[n] != '\0'; n++)
        if (str[n] >= 'A' && str[n] <= 'Z')
            str[n] = str[n] + 32;
    return (str);
}
