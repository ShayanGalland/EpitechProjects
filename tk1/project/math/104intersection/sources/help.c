/*
** EPITECH PROJECT, 2022
** re
** File description:
** tr
*/
#include "intersection.h"

int help()
{
    puts("USAGE\n");
    puts("\t./104intersection opt xp yp zp xv yv zv p\n\n");
    puts("DESCRIPTION\n");
    puts("\topt\t\tsurface option: 1 for a sphere, 2 for a cylinder, 3 for a cone\n");
    puts("\t(xp, yp, zp)\tcoordinates of a point by which the light ray passes through\n");
    puts("\t(xv, yv, zv)\tcoordinates of a vector parallel to the light ray\n");
    puts("\tp\t\tparameter: radius of the sphere, radius of the cylinder, or\n");
    puts("\t\t\tangle formed by the cone and the Z-axis\n");
    return 0;
}
