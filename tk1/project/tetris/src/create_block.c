/*
** EPITECH PROJECT, 2021
** tools
** File description:
** help
*/

#include "my.h"

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
    int ret = 0;
    char *block = NULL;
    char **block_array = NULL;


    for (int i = 0; str[i] != '\n'; i++)
        ret++;
    block = malloc(sizeof(char)*(my_strlen(str)-ret+1));
    for (int i = 0; i != my_strlen(str)-ret-1; i++)
        block[i] = str[ret+i+1];
    block_array = my_split(block_array, block, '\n');
    get_dim_array(game, file, block_array);
}

void fil_str(game_t *game, int file)
{
    char *path = NULL;
    char *buffer = NULL;
    char* dir = "tetriminos/";
    int len_buffer = 0;

    path = my_strcatt(dir, game->block[file].filename);
    open_read(path, &buffer, &len_buffer);
    array_block(game, file, buffer);
    free(path);
}

void find_block(game_t *game, char *path)
{
    DIR *fd = opendir(path);
    struct dirent *file;
    int i = 0;

    while (fd) {
        file = readdir(fd);
        if (file == NULL)
            break;
        if (file->d_name[0] != '.') {
            game->block[i].filename = file->d_name;
            fil_str(game, i);
            i++;
        }
    }
}

void count_block(char *path, game_t *game)
{
    DIR *fd = opendir(path);
    struct dirent *file;

    game->nb_block = 0;
    while (fd) {
        file = readdir(fd);
        if (file == NULL)
            break;
        if (file->d_name[0] != '.')
            game->nb_block++;
    }
    game->block = malloc(sizeof(piece_t)*game->nb_block);
    find_block(game, path);
    closedir (fd);
}