/*
** EPITECH PROJECT, 2021
** read_line
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

int read_line(char *read_buffer, char *write_buffer)
{
    reset_buffer(write_buffer, 0, 256);

    int idx = 0;
    for (; *read_buffer != '\n'; idx++, read_buffer++) {
        write_buffer[idx] = *read_buffer;
    }
    read_buffer++;
    idx++;
    write_buffer[idx] = '\0';
    
    return idx;
}
