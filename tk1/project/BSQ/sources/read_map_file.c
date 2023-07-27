/*
** EPITECH PROJECT, 2021
** read_map_file
** File description:
** y
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

char *read_map_file(char *map_path)
{
    int map_handle = open(map_path, O_RDONLY);
    if (!map_handle)
        return NULL;
    struct stat stat_info;
    stat(map_path, &stat_info);

    char *buffer = malloc(sizeof(char) * stat_info.st_size);
    if (read(map_handle, buffer, stat_info.st_size) == -1) {
        close(map_handle);
        free(buffer);
        return NULL;
    }
    close(map_handle);
    return buffer;
}
