#include <stdio.h>
#include <stdlib.h>

void l_putchar(char c)
{
    write(1, &c, 1);
}
int sh_putnbr(int nb)
{
    if (nb < 0){
        l_putchar('-');
        nb = -1 * nb;
    }
    if (nb/10) {
        sh_putnbr(nb/10);
        l_putchar(nb % 10 + '0');
    }
    if (nb < 10)
        l_putchar(nb + '0');
    return (0);
}

int show_combinations(void)
{
    for (int b = 0; b <= 7;b++) {
        for (int n = 1;n <= 8;n++) {
            for (int i = 2;i <= 9; i++) {
                if (b < n && n < i && b < i) {
                    sh_putnbr(b);
                    sh_putnbr(n);
                    sh_putnbr(i);
                    l_putchar(',');
                    l_putchar(' ');
                }
            }
        }
    }
    return 0;
}
