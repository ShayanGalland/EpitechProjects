#include <unistd.h>

int show_alphabet(void)
{
    write (1, "abcdefghijklmnopqrstuvwxyz", 26);
    return 0;
}
