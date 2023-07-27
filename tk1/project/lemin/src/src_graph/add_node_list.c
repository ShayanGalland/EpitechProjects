/*
** EPITECH PROJECT, 2022
** graphes
** File description:
** add_node_list
*/

#include "graph.h"
#include <stdlib.h>
#include <stddef.h>

node_list_t *add_node_list(int x)
{
    node_list_t *n = malloc(sizeof(node_list_t));

    if (n == NULL)
        return (NULL);
    n->name = x;
    n->ants = false;
    n->next = NULL;
    return (n);
}
