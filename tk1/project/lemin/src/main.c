/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "struct.h"
#include "lemin.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "graph.h"
#include "my.h"

int main(void)
{
    ants_t *ants = malloc(sizeof(ants_t));
    graph_t *g = NULL;

    init_struct(ants);
    g = new_graph(ants->nbr_rooms + 2, false);
    for (int i = 0; i != ants->nbr_tunnel; ++i) {
        add_edge(g, ants->tunnel[i][0], ants->tunnel[i][1]);
    }
    lemin(ants, g);
    return 0;
}
