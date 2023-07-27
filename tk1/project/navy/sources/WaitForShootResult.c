/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

int WaitForShootResult()
{
    WaitForBitsWritten(2);
    unsigned int id_message = extract_n_bits(signal_message.message_data, 0, 1);
    if(id_message != 3)
        return(84);
    WaitForBitsWritten(3);
    int result = extract_n_bits(signal_message.message_data, 2, 3);
    signal_message.current_bit = 0;
    signal_message.message_data = 0;
    return result;
}