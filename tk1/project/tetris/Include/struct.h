/*
** EPITECH PROJECT, 2021
** struct.h
** File description:
** how to have one variable that is actually a lot of variables
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct coord_s {
    int y;
    int x;
} coord_t;


typedef struct tab_s {
    char **tab;
    coord_t dim;
} tab_t;

typedef struct piece_s {
    tab_t piece;
    int is_valid;
    char *filename;
    int grav;
} piece_t;

typedef struct ctr_s {
    int key_left;
    int key_right;
    int key_drop;
    int key_quit;
    int key_pause;
} ctr_t;

typedef struct game_s {
    piece_t *block;
    int nb_block;
    coord_t current_pos;
    tab_t map;
    tab_t map2;
    int level;
    ctr_t ctr;
    piece_t *cur_block;
    int speed;
    int del;
    int mv;
    int score;
    int mx;
    int my;
} game_t;

#endif /* STRUCT_H_ */
