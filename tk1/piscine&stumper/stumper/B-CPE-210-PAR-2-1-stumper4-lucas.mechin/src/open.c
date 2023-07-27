/*
** EPITECH PROJECT, 2022
** open
** File description:
** open
*/

#include "necessary.h"

int open_read(char *file_path, char **data_buffer, int *data_buffer_length)
{
    struct stat stat_data;
    int fd = 0;

    stat(file_path, &stat_data);
    *data_buffer_length = stat_data.st_size;
    *data_buffer = malloc(sizeof(char)*(*data_buffer_length));
    if (!data_buffer)
        return 84;
    fd = open(file_path, O_RDONLY);
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

char *my_strcatt(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    int newLen = len1+len2+1;
    char *str = malloc(sizeof(char)*newLen);
    int offsetStr1 = 0;

    for (int i = 0; i < newLen-1; i++) {
        if (i < len1) {
            str[i] = str1[i];
            offsetStr1++;
        } else
            str[i] = str2[i-offsetStr1];
    }
       str[newLen-1] = '\0';
       return str;
}

void fil_str(game_t *game, int file)
{
    char *path = NULL;
    char *buffer = NULL;
    char* dir = "pokecfg/";
    int len_buffer = 0;

    path = my_strcatt(dir, game->block[file].filename);
    open_read(path, &buffer, &len_buffer);
    array_block(game, file, buffer);
    free(path);
}
