/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#define _SOLVER
#include "function.h"

int open_and_read_file(char *file_path, char **data_buffer, int *data_buffer_length)
{
    struct stat stat_data;
    stat(file_path, &stat_data);
    *data_buffer_length = stat_data.st_size;
    *data_buffer = malloc(sizeof(char) * (*data_buffer_length));
    if (!data_buffer)
        return 84;
    int fd = open(file_path, O_RDONLY);
    if (!fd)
        return 84;
    if (read(fd, *data_buffer, *data_buffer_length) == -1) {
        close(fd);
        free(*data_buffer);
        return 84;
    }
    close(fd);
    return 0;
}

void get_neighbours(cell_t* cell, int height, int width, cell_t ** maze, cell_t** neighbours)
{
    int i = 0;

    for (int i = 0; i < 4; i++)
        neighbours[i] = 0;
    if (cell->x-1 > 0 && maze[cell->y][cell->x-1].value == '*') {
        neighbours[i] = &maze[cell->y][cell->x-1];
        i++;
    }
    if (cell->x+1 < width && maze[cell->y][cell->x+1].value == '*') {
        neighbours[i] = &maze[cell->y][cell->x+1];
        i++;
    }
    if (cell->y-1 > 0 && maze[cell->y-1][cell->x].value == '*') {
        neighbours[i] = &maze[cell->y-1][cell->x];
        i++;
    }
    if (cell->y+1 < height && maze[cell->y+1][cell->x].value == '*') {
        neighbours[i] = &maze[cell->y+1][cell->x];
        i++;
    }
}