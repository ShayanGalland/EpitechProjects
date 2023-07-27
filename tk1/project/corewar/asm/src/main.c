/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <stdio.h>
#include "asm.h"
#include <unistd.h>

static void usage(char *binary)
{
    my_printf("USAGE\n%s file_name[.s]\nDESCRIPTION\n", binary);
    my_printf("file_name file in assembly language to be converted into ");
    my_printf("file_name.cor , an\nexecutable in the Virtual Machine.\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        usage(av[0]);
        return 0;
    }
    if (ac != 2) {
        write(2, "Check '-h' for more help\n", 26);
        return 84;
    }
    if (do_asm(av[1]) == -1)
        return 84;
    return 0;
}
