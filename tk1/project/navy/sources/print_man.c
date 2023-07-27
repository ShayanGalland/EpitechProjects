
/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

void print_man()
{
    write(1, "USAGE\n" ,6);
    write(1, "     ./navy [first_player_pid] navy_positions\n" ,46);
    write(1, "DESCRIPTION\n" ,12);
    write(1, "     first_player_pid: only for the 2nd player. pid of the first player.\n" ,73);
    write(1, "     navy_positions: file representing the positions of the ships.\n" ,67);
}