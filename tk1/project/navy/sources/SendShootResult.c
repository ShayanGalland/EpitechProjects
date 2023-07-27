/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

void SendShootResult(short pid, int result)
{
    number_to_signal(pid, 3, 2);
    number_to_signal(pid, result, 1);
}