/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** project in c
*/
#include "function.h"

int enemies(char **argv, game_t *game_t)
{
    int fp;
    int one_read;
    if (argv[1][0] != '-' && argv[1][1] !=  'h')
        fp = open(argv[1] ,O_RDONLY);
    else
        fp = open(argv[2], O_RDONLY);
    char* buffer = malloc(sizeof(char) * 30000);
    one_read = read(fp, buffer, 30000);
    if(one_read == -1) {
        close(fp);
        return 84;
    }
    buffer[one_read] = '\0';
    game_t->rd_mp = buffer;
    close(fp);
    return 0;
}