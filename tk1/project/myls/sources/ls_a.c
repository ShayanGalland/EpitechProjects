/*
** EPITECH PROJECT, 2021
** y
** File description:
** y
*/
#include "function.h"

int ls_a()
{
    struct dirent *d;
    DIR *dir;

    if ((dir = opendir(".")) == NULL) {
        closedir(dir);
	return 0;
    }
    while (d != NULL) {
        d = readdir(dir);
        if (d == NULL)
            break;
        my_putstr(d->d_name);
        my_putchar(' ');
    }
    my_putchar('\n');
    closedir(dir);
    return 0;
}
