/*
** EPITECH PROJECT, 2022
** car_directions.c
** File description:
** car_directions
*/
#include "../include/my.h"

void direction(float left, float right, float dist)
{
    dprintf(1, "WHEELS_DIR:");
    if (left < right)
        dprintf(1, "-");
    if (dist <= 1000 && dist > 800)
        dprintf(1, "0.15\n");
    if (dist <= 200 && dist > 150)
        dprintf(1, "0.7\n");
    if (dist <= 150)
        dprintf(1, "1\n");
    if (dist <= 800 && dist > 300)
        dprintf(1, "0.15\n");
    if (dist <= 300 && dist > 200)
        dprintf(1, "0.45\n");
    if (dist > 2000)
        dprintf(1, "0.05\n");
    if (dist <= 2000 && dist > 1000)
        dprintf(1, "0.1\n");
}