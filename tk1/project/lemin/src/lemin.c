/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** lemin
*/

#include "struct.h"
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "graph.h"

int check_tunnel(adjency_list_t *tunnel, int pos, ants_t *ants)
{
    node_list_t *n;

    n = tunnel[pos].start;
    while (n != NULL) {
        if (n->name == ants->end.nbr) {
            my_printf("end at %i\n", pos);
            return -1;
        }
        pos = n->name;
        if (n->ants == false)
            pos = check_tunnel(tunnel, pos, ants);
        n->ants == true;
        if (pos == -1)
            return -1;
        n = n->next;
    }
    return 0;
}

void lemin(ants_t *ants, graph_t *g)
{
    ants = ants;
    g = g;
}
