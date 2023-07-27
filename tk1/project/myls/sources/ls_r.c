/*
** EPITECH PROJECT, 2021
** y
** File description:
** y
*/
#include "function.h"

int ls_r()
{
    struct dirent *d;
    DIR *dir;
    int count = 0;

    if ((dir = opendir(".")) == NULL) {
        closedir(dir);
		return 0;
    }
    while (d != NULL) {
        d = readdir(dir);
        count++;
    }
    count--;
    for (int n = 0;n != count;) {
    ls_br(count);
    count--;
	}
    my_putchar('\n');
    closedir(dir);
    return 0;
}

