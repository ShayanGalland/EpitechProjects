/*
** EPITECH PROJECT, 2021
** struct
** File description:
** struct
*/

#include "struct.h"
#include "graph.h"

#ifndef LEMIN_H_
    #define LEMIN_H_

int init_struct(ants_t *ants);
void lemin(ants_t *ants, graph_t *g);
int count_rooms(char **tab);
int count_end(char **tab);
int count_tunnel(char **tab);
void fill_start(ants_t *ants, char ***tab);
void fill_data(rooms_t *room, char *str);
int check_is_tunnel(char *str);
void skip_comment(char ***tab);
void init_rooms(ants_t *ants, char ***tab);
int error(char *buf);
int read_from_redi(char **buf);
char **clear_comments(char **tab);
int count_end(char **tab);
int check_is_room(char *str);
int check_in_rooms(char *str);
int check_error_tunnel(char **tab);

#endif
