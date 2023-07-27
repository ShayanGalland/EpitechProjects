/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

void number_to_signal(short pid, int number, int bits_to_write)
{
    for(int i = 0; i < bits_to_write; i++) {
        if((number >> i) & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(1);
    }
}
