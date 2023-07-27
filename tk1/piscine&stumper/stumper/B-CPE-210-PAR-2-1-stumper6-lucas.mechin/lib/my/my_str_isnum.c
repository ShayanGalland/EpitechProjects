/*
** EPITECH PROJECT, 2021
** my_str_isnum
** File description:
** my_str_isnum
*/

int my_str_isnum(char const *str)
{
    for (int a = 0; str[a]; a++) {
        if (!(str[a] >= '0' && str[a] <= '9'))
            return 69;
    }
    return 0;
}
