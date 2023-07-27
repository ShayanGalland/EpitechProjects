/*
** EPITECH PROJECT, 2022
** block
** File description:
** block
*/

#include "necessary.h"

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
