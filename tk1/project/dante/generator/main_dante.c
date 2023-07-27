/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "function.h"

int my_strcmp(const char *str1, const char *str2)
{
    int str1_size = strlen(str1);
    int str2_size = strlen(str2);
    int i = 0;

    if (str1_size != str2_size)
        return 0;
    while (i < str1_size) {
        if (str1[i] != str2[i])
            return 0;
        i++;
    }
    return 1;
}

unsigned int rand_num(int min, int max)
{
    int result  = rand() % ((max + 1) - min) + min;
    return result;
}

void print_maze(int x, int y, cell_t **maze)
{
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++)
            printf("%c", maze[i][j].value);
        if (i != x-1)
            printf("\n");
    }
}

int small_lab(int y, int x)
{
    if (x == 1 && y == 1) {
        printf("*");
        return 0;
    }
    if (x == 1) {
        for (int i = 0; i < y-1; i++)
            printf("*\n");
        printf("*");
        return 0;
    }
    return 1;
}

int main(int argc, char **argv)
{
    cell_t **maze;
    int x = atoi(argv[2]);
    int y = atoi(argv[1]);

    if (argc != 3 && argc != 4)
        return 84;
    if (!small_lab(x, y))
        return 0;
    srand(time(NULL));
    if (my_strcmp(argv[3], "perfect"))
        maze = perfect(x, y);
    else if (my_strcmp(argv[3], "imperfect"))
        maze = imperfect(x, y);
    print_maze(x,y, maze);
    return 0;
}
