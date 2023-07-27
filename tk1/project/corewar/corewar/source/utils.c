#include "functions.h"

short short_to_little_endian(short nbr)
{
    return (nbr >> 8) | (nbr << 8);
}
int int_to_little_endian(int nbr)
{
    return ((nbr >> 24) & 0xff) | ((nbr << 8) & 0xff0000) | ((nbr >> 8) & 0xff00) | ((nbr << 24) & 0xff000000);
}
short bytes_to_short(char b1, char b2)
{
    short s1 = b1;
    short s2 = b2;
    return (s1 << 8) | s2;
}

int bytes_to_int(char b1, char b2, char b3, char b4)
{
    return b1 + (b2 << 8) + (b3 << 16) + (b4 << 24);
}
