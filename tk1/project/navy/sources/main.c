/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

signal_message_t signal_message;

int main(int argc, char** argv) 
{
    int player_id = 0;
    signal_message.current_bit = 0;
    signal_message.message_data = 0;
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    if(argc == 1) {
        print_man();
        return 84;
    }
    if(argc == 2 || argc == 3)
        game_make(argv, argc, player_id);
    return 0;
}
