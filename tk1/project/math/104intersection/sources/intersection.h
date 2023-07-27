/*
** EPITECH PROJECT, 2022
** inter
** File description:
** erc
*/

#ifndef INTERSECTION
    #define INTERSECTION

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
typedef struct intersection_s {
    float opt;
    float xp; 
    float yp;
    float zp; 
    float xv;
    float yv;
    float zv;
    float p;
} intersection_t;
void m_t(float x1, float x2, intersection_t in);
void m_o(float x, intersection_t in);
int cone(int ac, char **av, intersection_t in);
int cylindre(int ac, char **av, intersection_t in);
int sphere(int ac, char **av, intersection_t in);

#endif
