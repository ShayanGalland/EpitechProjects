/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

void WaitShoot(short otherplayer_pid,char ** my_map)
{
    write(1, "waiting for enemy’s attack...\n", 32);
    char x = -1;
    char y = -1;
    WaitForShoot(&x, &y);
    if(x != 8 && y != 8) {
        int shoot_result = my_map[x][y] != '.' ? 1 : 0;
        SendShootResult(otherplayer_pid, shoot_result);
        print_shoot_result(x,y, shoot_result, my_map);
    }
}