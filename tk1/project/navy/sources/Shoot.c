/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

void Shoot(short otherplayer_pid, char ** their_map) 
{
    char x = -1;
    char y = -1;
    read_player_input(&x, &y);
    SendShoot(otherplayer_pid, x, y);
    int shoot_result = WaitForShootResult();
    print_shoot_result(x,y, shoot_result, their_map);
}