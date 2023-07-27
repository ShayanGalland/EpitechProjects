/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

void re_game(int otherplayer_pid, int player_id, char **my_map, char **their_map)
{
    while(1) {
        write(1, "my positions:\n", 14);
        print_map(my_map);
        write(1, "\n", 1);
        write(1, "enemy’s positions:\n", 21);
        print_map(their_map);
        write(1, "\n", 1);
        if(isFinish(my_map, their_map) == 1)
            break;
        player_id == 1 ? Shoot(otherplayer_pid, their_map) : WaitShoot(otherplayer_pid, my_map);
        player_id == 2 ? Shoot(otherplayer_pid, their_map) : WaitShoot(otherplayer_pid, my_map);
    }
    free_map(my_map);
    free_map(their_map);
}
