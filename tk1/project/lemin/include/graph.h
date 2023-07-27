/*
** EPITECH PROJECT, 2022
** graph
** File description:
** graph
*/

#ifndef __GRAPHE_H_
    #define __GRAPHE_H_

//def bool//
typedef enum {
    false,
    true
} bool;

//def noeud sommet//
typedef struct node_list_s {
    bool ants;
    int name;
    struct node_list_s *next;
} node_list_t;

//def list adjaencenc//
typedef struct adjency_list_s {
    node_list_t *start;
} adjency_list_t;

//def graph//
typedef struct graph_s {
    bool is_oriented;
    int nbr_sommet;
    adjency_list_t *tab_neighbours;
} graph_t;

//proto//
graph_t *new_graph(int sommet, bool is_oriented);
bool is_empty_graph(graph_t *graph);
node_list_t *add_node_list(int x);
void free_graph(graph_t *g);
void add_edge(graph_t *g, int src, int dest);
void display_graph(graph_t *g);
#endif/* !__GRAPHE_H_ */
