/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

int WaitForShoot(char* x, char* y)
{
    WaitForBitsWritten(2);
    unsigned int id_message = extract_n_bits(signal_message.message_data, 0, 1);
    if(id_message != 2)
        return(84);
    WaitForBitsWritten(10);
    *x = extract_n_bits(signal_message.message_data, 2, 5);
    *y = extract_n_bits(signal_message.message_data, 6, 10);
    signal_message.current_bit = 0;
    signal_message.message_data = 0;
    return 0;
}