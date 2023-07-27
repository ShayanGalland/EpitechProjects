/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

void con_pid(int otherplayer_pid, int player_id, char **my_map, char **their_map)
{
    if(otherplayer_pid == 0) {
        player_id = 1;
        write(1, "waiting for enemy connection...\n", 32);
        write(1, "\n", 1);
        otherplayer_pid = WaitForEnnemyConnected();
        write(1, "enemy connected\n", 16);
        SendConfirmationConnection(otherplayer_pid);
    } 
    else {
        player_id = 2;
        SendEnnemyConnected(otherplayer_pid);
        WaitForConfirmationConnection();
        write(1, "successfully connected\n", 23);
    }
    re_game(otherplayer_pid, player_id, my_map, their_map);
}
