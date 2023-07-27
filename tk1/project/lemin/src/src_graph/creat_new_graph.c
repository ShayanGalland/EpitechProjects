/*
** EPITECH PROJECT, 2022
** graphes
** File description:
** creat_new_graph
*/

#include "graph.h"
#include <stdlib.h>
#include <stddef.h>

graph_t *new_graph(int nbr_sommet, bool is_oriented)
{
    graph_t *element;

    if ((element = malloc(sizeof(*element))) == NULL)
        return (NULL);
    element->is_oriented = is_oriented;
    element->nbr_sommet = nbr_sommet;
    if ((element->tab_neighbours = malloc
    (sizeof(adjency_list_t) * nbr_sommet)) == NULL)
        return (NULL);
    for (int i = 0; i != nbr_sommet; ++i)
        element->tab_neighbours[i].start = NULL;
    return (element);
}
