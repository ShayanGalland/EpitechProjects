/*
** EPITECH PROJECT, 2021
** y
** File description:
** y
*/
#include "function.h"

int ls_l()
{
    struct
        dirent *d;
    DIR *dir;
    struct
        stat stats;

    if ((dir = opendir(".")) == NULL) {
        closedir(dir);
        return 0;
    }
    while ((d != NULL)) {
        d = readdir(dir);
        if (d == NULL)
            break;
        lstat(d->d_name, &stats);
        my_putstr(d->d_name);
        my_putnbr(stats.st_mode);
        my_putchar('\n');
    }
    closedir(dir);
    return 0;
}
