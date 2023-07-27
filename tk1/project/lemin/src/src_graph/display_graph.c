/*
** EPITECH PROJECT, 2022
** graphes
** File description:
** display_graph
*/

#include "graph.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "my.h"

void display_graph(graph_t *g)
{
    node_list_t *n;

    if (g == NULL)
        return;
    for (int i = 0; i != g->nbr_sommet; ++i) {
        n = g->tab_neighbours[i].start;
        my_printf("(%d) : ", i);
        while (n != NULL) {
            my_printf("%d, ", n->name);
            n = n->next;
        }
        my_printf("NULL\n");
    }
}
