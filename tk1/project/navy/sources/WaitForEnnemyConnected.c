/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

short WaitForEnnemyConnected() 
{
    WaitForBitsWritten(2);
    unsigned int id_message = extract_n_bits(signal_message.message_data, 0, 1);
    if(id_message != 0)
        return(84);
    WaitForBitsWritten(18);
    short pid = extract_n_bits(signal_message.message_data, 2, 18);
    signal_message.current_bit = 0;
    signal_message.message_data = 0;
    return pid;
}