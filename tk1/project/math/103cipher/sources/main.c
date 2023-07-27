/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c 103cipher
*/
#include "functions.h"

int main(int argc, char **argv)
{
    if (argc == 4) {
        char *message = argv[1];
        char *key = argv[2];
        int flag = atoi(argv[3]);
        if (flag == 1)
            return uncipher(message, key);
        else
            return cipher(message, key);
    }
    else
        return 84;
}
