/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

int extract_n_bits(unsigned int data, unsigned a, unsigned b)
{
    unsigned int mask = create_bits_mask(a,b);
    unsigned result = (mask & data) >> a;
    return result;
}
