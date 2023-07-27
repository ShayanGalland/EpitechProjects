/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** project in c
*/
#include "function.h"

void help(char **argv, int argc)
{
    if(my_strcmp(argv[1], "-h") == 0 && argc >= 2) {
        write(1, "Finite runner created with CSFML.\n" ,34);
        write(1, "\n" ,1);
        write(1, "USAGE\n" ,6);
        write(1, "./my_runner map.txt\n" ,20);
        write(1, "USER INTERACTIONS\n" , 18);
        write(1, "SPACE_KEY     jump.\n" ,20);
    }
    else {
        if (argc >= 3)
            write(1, "error retry with -h\n" ,20);
    }
}