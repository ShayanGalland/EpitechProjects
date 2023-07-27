/*
** EPITECH PROJECT, 2021
** y
** File description:
** y
*/
#include "function.h"

int ls()
{
    struct dirent *d;
    DIR *dir = opendir(".");

    while (d != NULL) {
        d = readdir(dir);
        if (d->d_name[0] == '.')
            d = readdir(dir);
        if (d == NULL) {
            my_putchar('\n');
            closedir(dir);
            return 0;
        }
        my_putstr(d->d_name);
        my_putchar(' ');
    }
    closedir(dir);
    return 0;
}
