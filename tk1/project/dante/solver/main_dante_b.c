/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#define _SOLVER
#include "function.h"

int check_neighbours(stack_t* stack, set_t* visited, cell_t* myCell, cell_t* neighbour)
{
    if (!neighbour)
        return 0;
    if (set_contains(visited, neighbour, &compare_cell))
        return 0;
    neighbour->prev = myCell;
    stack_push(stack, neighbour);
    return 1;
}

void mark_solution(cell_t* myCell, cell_t ** maze)
{
    myCell->value = 'o';
    cell_t* prev = myCell->prev;
    while (1) {
        maze[prev->y][prev->x].value = 'o';
        prev = prev->prev;
        if (prev == 0)
            break;
    }
}

void resolve_maze(int height, int width, cell_t ** maze)
{
    cell_t** neighbours = malloc(sizeof(cell_t*)*4);
    cell_t* start = &maze[0][0];
    cell_t* end = &maze[height-1][width-1];
    stack_t* stack = create_stack(10);
    set_t* visited = create_set(10);

    memset(neighbours, 0, sizeof(cell_t*)*4);
    get_neighbours(start, height, width, maze, neighbours);
    get_neighbours(end, height, width, maze, neighbours);
    stack_push(stack, start);
    while (stack_isEmpty(stack) == 0) {
        cell_t* myCell = stack_pop(stack);
        set_add(visited, myCell, &compare_cell);
        if (compare_cell(myCell, end) == 1) {
            mark_solution(myCell, maze);
            break;
        }
        get_neighbours(myCell, height, width, maze, neighbours);
        for (int i = 0; i < 4;i++)
            check_neighbours(stack, visited, myCell, neighbours[i]);
    }
}

void print_maze(int x, int y, cell_t **maze)
{
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%c", maze[i][j].value);
        }
        if (i != x-1)
            printf("\n");
    }
}

int no_end(int x, int y, cell_t **maze)
{
    int n = 0;

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (maze[i][j].value == 'o')
                n++;
        }
    }
    if (n >= 1)
        return 1;
    else
        return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    char *buffer = NULL;
    int data_buffer_len = 0;
    if (!open_and_read_file(argv[1], &buffer, &data_buffer_len)) {
        int width = 0;
        int height = 0;
        for (int i = 0; i < data_buffer_len; i++) {
            if (buffer[i] == '\n')
                height++;
            if (height == 0)
                width++;
        }
        height++;
        cell_t **maze = create_cells(height, width);
        int x = -1;
        int y = 0;
        for (int i = 0; i < data_buffer_len; i++) {
            if (buffer[i] == '\n') {
                y++;
                x = -1;
            }
            else {
                x++;
                maze[y][x].value = buffer[i];
                maze[y][x].x = x;
                maze[y][x].y = y;
            }
        }
        maze[0][0].prev = 0;
        resolve_maze(height, width, maze);
        if (!no_end(height, width, maze)) {
            printf("no solution found");
            return 0;
        }
        print_maze(height, width, maze);
    }
    else
        return 84;
    return 0;
}