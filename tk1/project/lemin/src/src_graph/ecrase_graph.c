/*
** EPITECH PROJECT, 2022
** graphes
** File description:
** ecrase_graph
*/

#include "graph.h"
#include <stdlib.h>
#include <stddef.h>

void free_graph(graph_t *g)
{
    node_list_t *n;
    node_list_t *tmp;

    if (g == NULL)
        return;
    if (g->tab_neighbours) {
        for (int i = 0; i < g->nbr_sommet; ++i) {
            n = g->tab_neighbours[i].start;
            while (n != NULL) {
                tmp = n;
                n = n->next;
                free(tmp);
            }
        }
        free(g->tab_neighbours);
    }
    free (g);
}
