/*
** EPITECH PROJECT, 2021
** y
** File description:
** y
*/
#include "function.h"

void ls_flags(char **argv, int i)
{
    if (argv[i][1] == 'a')
        ls_a();
    if (argv[i][1] == 'l')
        ls_l();
    if (argv[i][1] == 'r')
        ls_r();
    if (argv[i][1] == 'd')
        ls_d();
}
