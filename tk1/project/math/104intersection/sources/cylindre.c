/*
** EPITECH PROJECT, 2022
** ghf
** File description:
** yetrtbe
*/
#include "intersection.h"

int cylindre(int ac, char **av, intersection_t in)
{
    float a = pow(in.xv, 2) + pow(in.yv, 2);
    float b =  2 * in.xp * in.xv + 2 * in.yp * in.yv;
    float c = pow(in.xp, 2) + pow(in.yp, 2) - pow(in.p, 2);
    float delta = pow(b, 2) - (4 * a * c);
    float x1 = 0;
    float x2 = 0;
    printf("Cylinder of radius %1.0f\n", in.p);
    printf("Line passing through the point (%1.0f, %1.0f, %1.0f) ", in.xp, in.yp, in.zp);
    printf("and parallel to the vector (%1.0f, %1.0f, %1.0f)\n", in.xv, in.yv, in.zv);
    if (delta < 0)
        printf("No intersection point.\n");
    if (delta == 0) {
        x1 = -b/2*a;
        m_o(x1, in);
    }
    if (delta > 0) {
        x1 = (-b - sqrt(delta)) / (2 * a);
        x2 = (-b + sqrt(delta)) / (2 * a);
        m_t(x1, x2, in);
    }
    return 0;
}
