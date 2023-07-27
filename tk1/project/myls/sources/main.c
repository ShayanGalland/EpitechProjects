/*
** EPITECH PROJECT, 2021
** y
** File description:
** y
*/
#include "function.h"

int main(int argc, char **argv)
{
    int e = 0;

    if (argc == 1) {
        ls();
        return 0;
    }
    return 0;
    for (int i = 1;i != argc;i++) {
        e++;
        if (argv[e][0] == '-')
            ls_flags(argv, e);
        else
            return 84;
		return 0;
    }
}
