/*
** EPITECH PROJECT, 2022
** utils
** File description:
** utils
*/

#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../../include/my.h"

int get_program_size(char **array)
{
    int count = 0;

    for (int i = 0; array[i] != NULL; i++) {
        count++;
    }
    return count;
}

char **reading_file(char const *filepath)
{
    FILE *file;
    char **buf = NULL;
    size_t len = 0;

    buf = malloc(sizeof(char*) * 201);
    for (int i = 0; i < 201; i++)
        buf[i] = NULL;
    file = fopen(filepath, "r");
    for (int i = 0; i < 200; i++) {
        getline(&buf[i], &len, file);
        if (buf[i][0] == 0) {
            buf[i] = NULL;
            break;
        }
    }
    for (int i = 0; buf[i] != NULL; i++)
        for (int y = 0; buf[i][y] != '\0'; y++)
            if (buf[i][y] == '\n')
                buf[i][y] = '\0';
    return buf;
}

int is_last_path(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '/')
            return 1;
    return 0;
}

int convert(int nbr)
{
    int converted = 0;

    converted |= ((0xff & nbr) << 24);
    converted |= (((0xff << 8) & nbr) << 8);
    converted |= (((0xff << 16) & nbr) >> 8);
    converted |= (((0xff << 24) & nbr) >> 24);
    return converted;
}

int is_except(char *str)
{
    char *except[] = {"live", "zjmp", "fork", "lfork", NULL};

    for (int i = 0; except[i] != NULL; i++)
        if (my_strcmp(str, except[i]) == 0)
            return 1;
    return 0;
}