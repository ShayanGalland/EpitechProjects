/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

unsigned create_bits_mask(unsigned a, unsigned b)
{
   unsigned mask = 0;
   for (int i=a; i<=b; i++)
       mask |= 1 << i;
   return mask;
}