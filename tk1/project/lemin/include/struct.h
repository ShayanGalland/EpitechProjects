/*
** EPITECH PROJECT, 2021
** struct
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct rooms_s {
    int nbr;
    int x;
    int y;
} rooms_t;

typedef struct ants_s {
    int nbr_ants;
    int nbr_rooms;
    int nbr_end;
    rooms_t start;
    rooms_t *rooms;
    rooms_t end;
    int **tunnel;
    int nbr_tunnel;
    int pos;
} ants_t;

#endif