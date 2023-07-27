/*
** EPITECH PROJECT, 2022
** error rooms
** File description:
** error rooms
*/

#include "lemin.h"
#include "my.h"
#include <unistd.h>

int check_in_rooms(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '#')
            break;
        if ((str[i] < '0' || str[i] > '9') && str[i] != ' ') {
            write(2, "Rooms can't countain letters\n", 30);
            return -1;
        }
    }
    return 0;
}

static int check_in(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-') {
            write(2, "Tunnel can countain only numbers\n", 34);
            return -1;
        }
    return 0;
}

int check_error_tunnel(char **tab)
{
    int ret = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (check_is_tunnel(tab[i]) == 1)
            ret = check_in(tab[i]);
        if (ret == -1)
            return -1;
    }
    return 0;
}