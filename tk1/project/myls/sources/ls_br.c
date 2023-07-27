/*
** EPITECH PROJECT, 2021
** y
** File description:
** y
*/
#include "function.h"

void ls_br(int count)
{
	int n = count;
	struct dirent *d;
	DIR *dir = opendir(".");

	for (int i = 0;i != n;i++) {
		count--;
		d = readdir(dir);
        if (count == 0) {
            my_putstr(d->d_name);
            my_putchar(' ');
        }
    }
}
