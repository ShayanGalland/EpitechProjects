/*
** EPITECH PROJECT, 2022
** create
** File description:
** create
*/

#include "asm.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int name_lenght(char *name)
{
    int count = 0;

    while (name[count] != '.' && name[count + 1] != 's')
        count++;
    return count;
}

void fill_name(char **new, char *name)
{
    char *suffix = ".cor";
    int i = 0;

    for (; name[i] != '.'; i++)
        (*new)[i] = name[i];
    for (int j = 0; suffix[j] != '\0'; i++, j++)
        (*new)[i] = suffix[j];
    (*new)[i] = '\0';
}

int create_cor_file(char *filename)
{
    char *new = NULL;
    int fd;

    while (is_last_path(filename) == 1)
        filename++;
    new = malloc(sizeof(char) * (name_lenght(filename) + 5));
    if (new == NULL)
        return -1;
    fill_name(&new, filename);
    fd = open(new, O_CREAT | O_WRONLY, 0777);
    if (fd == -1)
        return -1;
    return fd;
}
