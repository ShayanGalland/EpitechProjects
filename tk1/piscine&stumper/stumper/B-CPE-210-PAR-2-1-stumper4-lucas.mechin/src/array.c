/*
** EPITECH PROJECT, 2022
** array
** File description:
** array
*/

#include "necessary.h"

void get_dim_array(game_t *game, int file, char **block_array)
{
    int col = 0;
    int row = -1;
    int c = 0;

    for (int i = 0; block_array[i] != NULL; i++) {
        c = 0;
        for (int j = 0; block_array[i][j] != '\0'; j++)
            c++;
        if (c > col)
            col = c;
        row++;
    }
    game->block[file].piece.tab = block_array;
    game->block[file].piece.dim.x = col;
    game->block[file].piece.dim.y = row;
}

void array_block(game_t *game, int file, char *str)
{
    char *block = NULL;
    char **block_array = NULL;

     block = malloc(sizeof(char)*(my_strlen(str)+1));
     for (int i = 0; i != my_strlen(str); i++)
         block[i] = str[i];
     block_array = my_split(block_array, block, ';');
     get_dim_array(game, file, block_array);
}
