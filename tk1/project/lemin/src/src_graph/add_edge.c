/*
** EPITECH PROJECT, 2022
** graphes
** File description:
** add_edge
*/

#include "graph.h"
#include <stdlib.h>
#include <stddef.h>

void add_edge(graph_t *g, int src, int dest)
{
    node_list_t *n = add_node_list(dest);

    n->next = g->tab_neighbours[src].start;
    g->tab_neighbours[src].start = n;
    if (!g->is_oriented) {
        n = add_node_list(src);
        n->next = g->tab_neighbours[dest].start;
        g->tab_neighbours[dest].start = n;
    }
}
