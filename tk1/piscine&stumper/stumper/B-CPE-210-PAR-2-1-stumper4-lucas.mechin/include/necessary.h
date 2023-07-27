/*
** EPITECH PROJECT, 2021
** include
** File description:
** navy
*/

#ifndef STUMP
    #define STUMP
    #include <sys/types.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include "my.h"
    #include "struct.h"
    #include <dirent.h>
    #include <signal.h>
    #include <stdio.h>
    #include <sys/stat.h>
    #include <fcntl.h>

void find_block(game_t *game, char *path);
void fil_str(game_t *game, int file);
char **my_split(char **tab, char *str, char s);
char **my_split2(char **tab, char *str, char s, char c);
char *file_open(char const *filepath);
void array_block(game_t *game, int file, char *str);
void count_block(char *path, game_t *game);

#endif /* !STUMP */
