#include <unistd.h>
#include <stdlib.h>

void ly_putchar(char c)
{
    write(1, &c, 1);
}
int show_number(int nb)
{
    if (nb < 0) {
        ly_putchar('-');
        nb = -1 * nb;
    }
    if (nb/10) {
        show_number(nb/10);
        ly_putchar(nb % 10 + '0');
    }
    if (nb < 10)
        ly_putchar(nb + '0');
    return (0);
}
