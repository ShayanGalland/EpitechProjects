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

int find_quote(char c)
{
    if (c == 34)
        return 1;
    else
        return 0;
}

int skip_quote(char *str, int i)
{
    i += 2;
    while (str[i] != 34)
        i++;
    return i;
}

char *rm_start_spaces(char *str)
{
    int i = 0;
    int len = 0;
    char *new_str = NULL;

    if (str[0] != ' ')
        return str;
    while (str[i] == ' ')
        i++;
    len = my_strlen(str) - i;
    new_str = malloc(sizeof(char) * (len + 1));
    for (int n = 0; n < len; n++) {
        new_str[n] = str[i];
        i++;
    }
    return new_str;
}

int count_array(char **array)
{
    int i = 0;

    while (array[i] != 0)
        i++;
    return i;
}