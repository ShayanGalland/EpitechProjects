/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

void WaitForBitsWritten(unsigned int bitsToWait) 
{
    while(signal_message.current_bit < bitsToWait)
        usleep(100);
}
