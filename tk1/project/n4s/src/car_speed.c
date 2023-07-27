/*
** EPITECH PROJECT, 2022
** car_speed.c
** File description:
** car_speed
*/
#include "../include/my.h"

void speed(float dist)
{
    if (dist > 2500)
        dprintf(1, "CAR_FORWARD:1\n");
    if (dist <= 2500 && dist > 1000)
        dprintf(1, "CAR_FORWARD:0.7\n");
    if (dist <= 1000 && dist > 800)
        dprintf(1, "CAR_FORWARD:0.5\n");
    if (dist <= 800 && dist > 350)
        dprintf(1, "CAR_FORWARD:0.2\n");
    if (dist <= 350 && dist > 200)
        dprintf(1, "CAR_FORWARD:0.1\n");
    if (dist <= 150)
        dprintf(1, "CAR_BACKWARDS:1\n");
}