/*
** EPITECH PROJECT, 2022
** write header
** File description:
** write header
*/

#include "op.h"
#include "../../include/my.h"
#include "unistd.h"
#include "asm.h"

int write_dot(char *str, int fd)
{
    int len;

    while (str[0] != '"')
        str++;
    str++;
    str[my_strlen(str) - 1] = '\0';
    write(fd, str, my_strlen(str));
    return 0;
}

static char *fill_dot(char *str)
{
    while (str[0] != '"')
        str++;
    str++;
    str[my_strlen(str) - 1] = '\0';
    return str;
}

void init_header(char **tab, header_t *header)
{
    char *name = fill_dot(tab[0]);
    char *comment = fill_dot(tab[1]);
    char empty = 0;

    header->magic = convert(COREWAR_EXEC_MAGIC);
    for (int i = 0; i < PROG_NAME_LENGTH; i++)
        header->prog_name[i] = empty;
    header->prog_name[PROG_NAME_LENGTH] = '\0';
    for (int i = 0; i < COMMENT_LENGTH; i++)
        header->comment[i] = empty;
    header->comment[COMMENT_LENGTH] = '\0';
    // header->prog_size = get_program_size(tab);
    header->prog_size = 23;
    my_strcpy(header->prog_name, name);
    my_strcpy(header->comment, comment);
}