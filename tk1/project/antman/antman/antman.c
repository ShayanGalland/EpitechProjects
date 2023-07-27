/*
** EPITECH PROJECT, 2022
** y
** File description:
** y
*/

#include "functions.h"

int main(int argc, char** argv)
{
    if(argc != 3)
        return 84;
    return compress_file(argv[1], my_getnbr(argv[2]));
}
