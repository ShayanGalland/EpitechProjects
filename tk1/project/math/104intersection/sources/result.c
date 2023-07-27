/*
** EPITECH PROJECT, 2022
** yt
** File description:
** erc
*/
#include "intersection.h"

void m_o(float x, intersection_t in)
{
    float corx = in.xp + x * in.xv;
    float cory = in.yp + x * in.yv;
    float corz = in.zp + x * in.zv;
    printf("1 intersection point:\n");
    printf("(%1.3f, %1.3f, %1.3f)\n", corx, cory, cory);
}
