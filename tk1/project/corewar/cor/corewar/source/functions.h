#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define COREWAR_EXEC_MAGIC 0xea83f3

#define my_memset memset

int int_to_little_endian(int nbr);
short short_to_little_endian(short nbr);
short bytes_to_short(char b1, char b2);
int bytes_to_int(char b1, char b2, char b3, char b4);

#endif