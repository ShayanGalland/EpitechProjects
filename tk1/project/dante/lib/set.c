/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "set.h"

set_t *create_set(int max)
{
    set_t *set = malloc(sizeof(set_t));

    set->set = malloc(sizeof(void*)*max);
    set->max = max;
    set->count = 0;
    return set;
}

void set_realloc(set_t *set, int new_size)
{
    void** new_set = malloc(sizeof(void*)*new_size);
    for (int i = 0; i < set->max; i++)
        new_set[i] = set->set[i];
    free(set->set);
    set->set = new_set;
    set->max = new_size;
}

void set_add(set_t *set, void *x, predicate pred)
{
    int cmp = 0;

    for (int i = 0; i < set->count; i++) {
        cmp = pred(x, set->set[i]);
        if (cmp == 1)
            break;
    }
    if (cmp == 0) {
        if (set->count + 1 >= set->max)
            set_realloc(set,set->max*2);
        set->set[set->count] = x;
        set->count++;
    }
}

int set_contains(set_t *set, void *x, predicate pred)
{
    int cmp = 0;

    for (int i = 0; i < set->count; i++) {
        cmp = pred(x, set->set[i]);
        if (cmp == 1)
            break;
    }
    return cmp;
}
