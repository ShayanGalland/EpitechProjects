/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "function.h"

int all_visited(set_t *visited, cell_t **neighbours)
{
    int value = 1;

    for (int i = 0; i < 4; i++) {
        if (!neighbours[i])
            continue;
        if (!set_contains(visited, neighbours[i], &compare_cell)) {
            value = 0;
            break;
        }
    }
    return value;
}

void neighbour_param(cell_t **neighbours, int x, int y, cell_t ***map)
{

}

void create_maze_perfect(int x, int y, cell_t **map)
{
    cell_t **neighbours = malloc(sizeof(cell_t*)*4);
    cell_t *myCell = NULL;
    stack_t *stack = create_stack(10);
    set_t *visited = create_set(10);
    int r = 0;

    stack_push(stack, &map[0][0]);
    set_add(visited, &map[0][0], &compare_cell);
    while (stack_isEmpty(stack) == 0) {
        //neighbour_param(neighbours, x, y, &map);
        myCell = stack_pop(stack);
        neighbours[0] = NULL;
        neighbours[1] = NULL;
        neighbours[2] = NULL;
        neighbours[3] = NULL;
        if (myCell->x-2 > 0)
            neighbours[0] = &map[myCell->x-2][myCell->y];
        if (myCell->x+2 < x)
            neighbours[1] = &map[myCell->x+2][myCell->y];
        if (myCell->y-2 > 0)
            neighbours[2] = &map[myCell->x][myCell->y-2];
        if (myCell->y+2 < y)
            neighbours[3] = &map[myCell->x][myCell->y+2];
        if (all_visited(visited, neighbours))
            continue;
        stack_push(stack, myCell);
        for (int i = 0; i < 4; i++) {
            r = rand_num(0, 3);
            if (!neighbours[r])
                continue;
            if (set_contains(visited, neighbours[r], &compare_cell))
                continue;
            neighbours[r]->value = '*';
            switch(r) {
                case 0:
                    map[myCell->x-1][myCell->y].value = '*';
                break;

                case 1:
                    map[myCell->x+1][myCell->y].value = '*';
                break;

                case 2:
                    map[myCell->x][myCell->y-1].value = '*';
                break;

                case 3:
                    map[myCell->x][myCell->y+1].value = '*';
                break;
            }
            set_add(visited, neighbours[r], &compare_cell);
            stack_push(stack, neighbours[r]);
        }
    }
}

cell_t **perfect(int x, int y)
{
    cell_t **map = create_cells(x, y);

    map[0][0].value = '*';
    map[x-1][y-1].value = '*';
    map[x-2][y-1].value = '*';
    map[x-1][y-2].value = '*';
    create_maze_perfect(x, y, map);
    return map;
}