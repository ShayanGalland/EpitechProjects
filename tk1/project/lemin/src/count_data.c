/*
** EPITECH PROJECT, 2022
** count_data
** File description:
** count_data
*/

#include <stddef.h>
#include "my.h"

int count_tunnel(char **tab)
{
    int count = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (tab[i][0] == '#')
            i++;
        count++;
    }
    return count;
}

int check_is_tunnel(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '-')
            return 1;
    return 0;
}

int count_end(char **tab)
{
    int count = 0;

    while (check_is_tunnel(tab[0]) == 0) {
        if (tab[0][0] == '#')
            tab++;
        count++;
        tab++;
    }
    return count;
}

int check_is_room(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i + 1] != ' ')
            count++;
        if (str[i] == ' ' && str[i + 1] == '#') {
            count = 2;
            break;
        }
    }
    count++;
    if (count == 3)
        return 1;
    return 0;
}

int count_rooms(char **tab)
{
    int count = 0;

    while (check_is_tunnel(tab[0]) == 0) {
        if (tab[0][0] == '#')
            tab++;
        count++;
        tab++;
    }
    return count - 2;
}
