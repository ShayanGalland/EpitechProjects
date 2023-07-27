/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** my_strcmp
*/

int my_strlen(char const *str);

int my_strcmp(char const *src, char const *cmp)
{
    if (my_strlen(src) != my_strlen(cmp))
        return 1;
    for (int i = 0; cmp[i] != '\0'; i++) {
        if (src[i] != cmp[i])
            return 1;
    }
    if (src[my_strlen(cmp)] != '\0')
        return 1;
    return 0;
}
