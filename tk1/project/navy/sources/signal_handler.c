/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

void signal_handler(int signum)
{
    if (signum == SIGUSR1) {
        signal_message.current_bit++;
    } 
    else if (signum == SIGUSR2) {
        signal_message.message_data |= 1U << signal_message.current_bit;
        signal_message.current_bit++;
    }
}