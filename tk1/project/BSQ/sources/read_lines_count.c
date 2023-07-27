/*
** EPITECH PROJECT, 2021
** read_lines_count
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

void read_lines_count(int *lines_count, char *current_line, char ***map)
{
    *lines_count = my_getnbr(current_line);
    (*map) = malloc(sizeof(char *) * *lines_count);
}
