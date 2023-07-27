/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include "intersection.h"

int main(int ac, char **av)
{
    intersection_t in;
    
    if (ac == 2)
        if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
            help();
    if (ac != 9)
        return (84);
    in.opt = atof(av[1]);
    in.xp = atof(av[2]);
    in.yp = atof(av[3]);
    in.zp = atof(av[4]);
    in.xv = atof(av[5]);
    in.yv = atof(av[6]);
    in.zv = atof(av[7]);
    in.p = atof(av[8]);
    if (atof(av[1]) == 1)
        sphere(ac, av, in);
    if (atof(av[1]) == 2)
        cylindre(ac, av, in);
    if (atof(av[1]) == 3)
        cone(ac, av, in);
    return (0);
}
