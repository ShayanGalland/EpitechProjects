/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

void SendEnnemyConnected(short pid) 
{
    number_to_signal(pid, 0, 2);
    number_to_signal(pid, getpid(), 16);
}