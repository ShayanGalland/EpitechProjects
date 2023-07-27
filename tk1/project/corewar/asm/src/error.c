/*
** EPITECH PROJECT, 2022
** error
** File description:
** error
*/

#include "op.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "asm.h"
#include <stdlib.h>

int int_to_little_endian(int nbr)
{
    return ((nbr>>24)&0xff) | ((nbr<<8)&0xff0000) | ((nbr>>8)&0xff00) | ((nbr<<24)&0xff000000);
}

static int verif_open_read(char *filename)
{
    int fd = open(filename, O_RDONLY);
    char *buf = malloc(sizeof(char) * 10);

    if (fd == -1)
        return -1;
    if (read(fd, buf, 10) == -1)
        return -1;
    return 0;
}

int check_empty(char **tab)
{
    if (tab[0] == NULL)
        return -1;
    return 0;
}

int check_header(char ***tab)
{
    if (my_strncmp(tab[0][0], ".name ", 6) != 0)
        return -1;
    if (my_strncmp(tab[0][1], ".comment ", 9) != 0)
        return -1;
    (*tab += 2);
    return 0;
}

int handle_error(char *filename)
{
    char **tab = NULL;

    if (verif_open_read(filename) == -1)
        return -1;
    tab = reading_file(filename);
    if (check_empty(tab) == -1)
        return -1;
    while (tab[0][0] == '#')
        tab++;
    if (check_header(&tab) == -1)
        return -1;
    while (tab[0][0] == '\0') {
        if (tab[1][0] == '.')
            return -1;
        tab++;
    }
    return 0;
}