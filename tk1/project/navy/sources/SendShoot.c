/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

void SendShoot(short pid, char x, char y)
{
    number_to_signal(pid, 2, 2);
    number_to_signal(pid, x, 4);
    number_to_signal(pid, y, 4);
}