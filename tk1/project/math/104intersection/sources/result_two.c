/*
** EPITECH PROJECT, 2022
** re
** File description:
** tec
*/
#include "intersection.h"

void m_t(float x1, float x2, intersection_t in)
{
    float corx = in.xp + x1 * in.xv;
    float cory = in.yp + x1 * in.yv;
    float corz = in.zp + x1 * in.zv;

    printf("2 intersection points:\n");
    printf("(%1.3f, %1.3f, %1.3f)\n", corx, cory, cory);
    corx = in.xp + x2 * in.xv;
    cory = in.yp + x2 * in.yv;
    corz = in.zp + x2 * in.zv;
    printf("(%1.3f, %1.3f, %1.3f)\n", corx, cory, cory);
}
