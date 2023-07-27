#ifndef _MY_H
#define _MY_H

#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>
#include <errno.h>

struct map {
    char** map_static;
    char** map_entities;
    int rows;
    int cols;
    int x_player;
    int y_player;
};
typedef struct map map_t;

int check_line(char *line);
int check_map(const char *map_filepath, int *rows, int *cols);
map_t *read_map(const char *map_filepath);
char clean_tile(char tile, int entities);
void clean_map(char** map, int rows, int entities);

int is_game_win(map_t *map);
int is_game_lost(map_t *map);

void do_up(map_t *map);
void do_down(map_t* map);
void do_left(map_t* map);
void do_right(map_t* map);
void handle_move(int key, map_t* map);

#endif