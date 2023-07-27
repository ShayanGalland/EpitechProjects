/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** project main
*/

#include "../include/include.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int open_read(char *file_path, char **data_buffer, int *data_buffer_length)
{
    struct stat stat_data;
    int fd = 0;

    stat(file_path, &stat_data);
    *data_buffer_length = stat_data.st_size;
    *data_buffer = malloc(sizeof(char)*(*data_buffer_length));
    if (!data_buffer)
        return 84;
    fd = open(STDIN_FILENO, O_RDONLY);
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

int my_tablen(char **tab)
{
    int n = 0;

    for (n = 0; tab[n] != NULL; n++);
    return n;
}

char **open_file_into_array(char *file_path, int *len)
{
    char *buffer = NULL;
    char **array = NULL;
    int buff_len = 0;

    if (open_read(file_path, &buffer, &buff_len) == 84)
        exit(84);
    array = my_split(array, buffer, '\n');
    *len = my_tablen(array);
    return array;
}