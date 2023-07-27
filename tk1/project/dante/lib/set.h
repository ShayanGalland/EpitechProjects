/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#ifndef _SET_H
    #define _SET_H
    #include <stdlib.h>

struct set {
    void **set;
    int max;
    int count;
};
typedef struct set set_t;
typedef int(predicate)(void *a, void *b);

set_t *create_set(int max);
void set_realloc(set_t *set, int new_size);
void set_add(set_t *set, void *x, predicate pred);
int set_contains(set_t *set, void *x, predicate pred);

#endif