/*
** EPITECH PROJECT, 2021
** y
** File description:
** y
*/
#include "functions.h"

int my_putnbr(int n)
{
    int nb;

    if (n < 0) {
        my_putchar('-');
        n *= -1;
        my_putnbr(n);
        return (0);
    } else if (n > 9)
        my_putnbr(n / 10);
    nb = n % 10;
    my_putchar(nb + '0');
    return (0);
}

int my_getnbr(char const *str)
{
    int dest = 0;
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9' || str[i] != '+' && str[i] != '-')
            break;
        if (str[i] == '-')
            j++;
        i++;
    }
    while (str[i] != '\0') {
        while (str[i] >= '0' && str[i] <= '9')  {
            dest = dest * 10 + (str[i] - '0');
            i++;
        }
        dest = (j % 2 == 1) ? dest * (-1): dest;
        return (dest);
    }
}

void print_star (char size)
{
    my_putnbr(size);
}


int main (int argc, char **argv)
{
    if (argc == 1)
        return 0;
    if (argc > 2)
        return 84;
    if (argv[1][0] != '-')
        return 84;
    if (argv[1][1] <= '9'&& argv[1][1] >= '0')
        print_star(my_getnbr(argv[1][1]));
    else
        return 84;
    return 0;
}
