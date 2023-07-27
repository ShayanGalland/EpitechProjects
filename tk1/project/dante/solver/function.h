/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#ifndef _FUNCTIONS_H
    #define _FUNCTIONS_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <time.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include "../lib/set.h"
    #include "../lib/stack.h"
    #include "../commons/cell.h"
int open_and_read_file(char *file_path, char **data_buffer,
int *data_buffer_length);
void get_neighbours(cell_t* cell, int height, int width,
 cell_t ** maze, cell_t** neighbours);
#endif