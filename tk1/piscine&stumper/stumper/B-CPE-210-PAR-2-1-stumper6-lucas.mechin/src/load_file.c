/*
** EPITECH PROJECT, 2022
** load_file
** File description:
** load_file
*/

#include "necessary.h"
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char *load_file_in_mem(char const *filepath)
{
    int a;
    int size;
    char *buffer;
    struct stat buff;

    a = open(filepath, O_RDONLY);
    if (a == -1)
        return NULL;
    stat(filepath, &buff);
    size = buff.st_size;
    if (size == 0)
        return NULL;
    buffer = malloc(sizeof(char) * (size + 1));
    buffer[size] = '\0';
    read(a, buffer, size);
    close(a);
    return buffer;
}
